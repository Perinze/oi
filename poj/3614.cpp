#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	int C, L;
	cin >> C >> L;
	vector<P> cow;
	for (int i = 0; i < C; i++)
	{
		int minspf, maxspf;
		cin >> minspf >> maxspf;
		cow.push_back(make_pair(minspf, maxspf));
	}
	vector<P> lotion;
	for (int i = 0; i < L; i++)
	{
		int spf, cover;
		cin >> spf >> cover;
		lotion.push_back(make_pair(spf, cover));
	}
	sort(cow.begin(), cow.end());
	sort(lotion.begin(), lotion.end());
	int ans = 0, j = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < L; i++)
	{
		while (j < C && cow[j].first <= lotion[i].first)
		{
			q.push(cow[j].second);
			j++;
		}
		while (!q.empty() && lotion[i].second)
		{
			int least_max_spf = q.top();
			q.pop();
			if (least_max_spf < lotion[i].first) continue;
			ans++;
			lotion[i].second--;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
