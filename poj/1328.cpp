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

bool in_circle(double y, double x, double rx)
{
	// ry == 0
	int d2 = y * y + (x - rx) * (x - rx);
	if (d2 <= D * D)
	{
#ifdef DEBUG
		cout << "(" << x << ", " << y << ") in circle " << rx << endl;
#endif
		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "(" << x << ", " << y << ") not in circle " << rx << endl;
#endif
		return false;
	}
}

void clean(double rx)
{
#ifdef DEBUG
	cout << "clean(" << rx << ")\n";
#endif
	for (int i = 0; i < vertex.size(); i++)
	{
		double vy, vx;
		vy = vertex[i].first, vx = vertex[i].second;
		if (in_circle(vy, vx, rx))
		{
			vertex.erase(vertex.begin() + i);
			i--;
		}
	}
}

void cover(double y, double x)
{
#ifdef DEBUG
	cout << "cover(" << x << ", " << y << ")\n";
#endif
	double dx = D * D - y * y;
	dx = sqrt(dx);
	
	double rx = x - dx;	// left center of circle
	int lres = 0, rres = 0;
	for (int i = 0; i < vertex.size(); i++)
	{
		double vy, vx;
		vy = vertex[i].first, vx = vertex[i].second;
		if (in_circle(vy, vx, rx))
			lres++;
	}
#ifdef DEBUG
	cout << "lres = " << lres << endl;
#endif
	
	if (dx != 0)
	{
		rx = x + dx;
		for (int i = 0; i < vertex.size(); i++)
		{
			double vy, vx;
			vy = vertex[i].first, vx = vertex[i].second;
			if (in_circle(vy, vx, rx))
				rres++;
#ifdef DEBUG
			cout << "rres = " << rres << endl;
#endif
		}
	}
	if (lres < rres) rx = x + dx;
	else rx = x - dx;
	clean(rx);
#ifdef DEBUG
	cout << "vertex: ";
	for (int i = 0; i < vertex.size(); i++)
	{
		int vy = vertex[i].first, vx = vertex[i].second;
		cout << "(" << vx << ", " << vy << ") ";
	}
	cout << endl;
#endif
}

void solve()
{
	sort(vertex.begin(), vertex.end());
	int ans = 0;
	while (!vertex.empty())
	{
		vector<P>::reverse_iterator ite = vertex.rbegin();
		double y = ite->first, x = ite->second;
		if (y > D)
		{
			cout << -1 << endl;
			return;
		}
		cover(y, x);
		ans++;
		if (vertex.empty()) 
		{
			cout << ans << endl;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	for (int t = 1;; t++)
	{
		vertex.clear();
		cin >> N >> D;
		if (N == 0) break;
		for (int i = 0; i < N; i++)
		{
			double x, y;
			cin >> x >> y;
			vertex.push_back(make_pair(y, x));
		}
		cout << "Case " << t << ": ";
		solve();
	}
	return 0;
}
