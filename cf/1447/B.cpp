#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 2e9

typedef pair<int, int> P;

typedef long long ll;
int n, m;
int a[20][20];

void solve()
{
	cin >> n >> m;
	for (int i = 0; i <= n; i++) fill(a[i], a[i] + m + 1, INF);

	priority_queue<P, vector<P>, greater<P> > q;
	for (int i = 1 ; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] < 0) q.push(P(i, j));
		}
	}

	while (!q.empty())
	{
		P p = q.top(); q.pop();
		int y = p.first, x = p.second, v = a[y][x];
		int near, ny, nx;
		near = a[y - 1][x]; ny = y - 1; nx = x;
		if (a[y + 1][x] < near)
		{
			near = a[y + 1][x];
			ny = y + 1;
		}
		if (a[y][x - 1] < near)
		{
			near = a[y][x - 1];
			ny = y;
			nx = x - 1;
		}
		if (a[y][x + 1] < near)
		{
			near = a[y][x + 1];
			ny = y;
			nx = x + 1;
		}
		if (-v < near);
		else 
		{
			a[y][x] *= -1;
			a[ny][nx] *= -1;
			q.push(P(ny, nx));
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			res += a[i][j];
		}
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
