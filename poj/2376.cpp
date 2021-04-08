#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, T;
typedef long long ll;
typedef pair<int, int> P;

vector<P> cows;

void solve()
{
	sort(cows.begin(), cows.end());
	int ans = 0;
	int max_begin = 1;
	int max_end = 0;
	for (int i = 0; i < cows.size();)
	{
		if (cows[i].first > max_begin)
		{
			cout << -1 << endl;
			return;
		}
		for (; i < cows.size(); i++)
		{
			if (cows[i].first <= max_begin)
			{
				max_end = max(cows[i].second, max_end);
			}
			else break;
		}
		ans += 1;
		if (max_end >= T) break;
		max_begin = max_end + 1;
	}
	if (max_end < T) cout << -1 << endl;
	else cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		cows.push_back(make_pair(a, b));
	}
	solve();
	return 0;
}
