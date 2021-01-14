#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int vis[200010];

int bfs(int n, int k)
{
	if (n == k) return 0;

	memset(vis, -1, sizeof(vis));
	vis[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int p = q.front(); q.pop();
		int t = vis[p];
		//cout << "poping " << p << " time " << t << endl;

		if (p - 1 == k) return t + 1;
		if (p + 1 == k) return t + 1;
		if (2 * p == k) return t + 1;

		if (p > 0 && vis[p - 1] == -1)
		{
			vis[p - 1] = t + 1;
			q.push(p - 1);
		}
		if (p < 200000 && vis[p + 1] == -1)
		{
			vis[p + 1] = t + 1;
			q.push(p + 1);
		}
		if (p <= 100000 && vis[p * 2] == -1)
		{
			vis[2 * p] = t + 1;
			q.push(p * 2);
		}
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << endl;
	/*
	for (int i = 0; i <= k + 10; i++)
	{
		cout << vis[i] << ' ';
	}
	cout << endl;
	*/
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
