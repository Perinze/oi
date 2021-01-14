
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const int INF = 1000000010;

int cost[100001]; int p[100010];

void solve()
{
	int n; ll z;
	cin >> n >> z;

	ll res = 0;
	for (int i = 0; i <= z; i++)
	{
		cost[i] = INF;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		int a = p[i] % z;
		cost[a] = min(cost[a], p[i]);
	}
	for (int i = 0; i <= z / 2; i++)
	{
		if (cost[i] == INF && cost[z - i] == INF)
		{
			continue;
		}
		res += min(cost[i], cost[z - i]) * min(cost[i], cost[z - i]);
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
