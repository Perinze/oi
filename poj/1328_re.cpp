#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<double, double> P;

int N; double D;
vector<P> vertex;
vector<P> segment;

void getsegment(double y, double x, double &l, double &r)
{
	double dx = D * D - y * y;
	dx = sqrt(dx);
	l = x - dx;
	r = x + dx;
}

bool cross(double &l1, double &r1, double l2, double r2)
{
	if (l2 > r1) return false;
	if (l1 > r2) return false;
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	return true;
}

int count_segment()
{
	int ans = 0;
	while (!segment.empty())
	{
		double cl = segment[0].first, cr = segment[0].second;
		segment.erase(segment.begin());
		for (vector<P>::iterator ite = segment.begin(); ite != segment.end(); ite++)
		{
			if (cross(cl, cr, ite->first, ite->second))
			{
				segment.erase(ite);
				ite--;
			}
		}
		ans++;
	}
	return ans;
}

void solve()
{
	for (vector<P>::iterator ite = vertex.begin(); ite != vertex.end(); ite++)
	{
		double y = ite->first, x = ite->second;
		double l, r;
		getsegment(y, x, l, r);
		segment.push_back(make_pair(l, r));
	}
	sort(segment.begin(), segment.end());
	cout << count_segment() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int t = 1;; t++)
	{
		vertex.clear();
		cin >> N >> D;
		if (N == 0) break;
		bool no_solution = false;
		for (int i = 0; i < N; i++)
		{
			double x, y;
			cin >> x >> y;
			if (y > D)
			{
				no_solution = true;
			}
			vertex.push_back(make_pair(y, x));
		}
		cout << "Case " << t << ": ";
		if (no_solution)
		{
			cout << -1 << endl;
			continue;
		}
		solve();
	}
	return 0;
}
