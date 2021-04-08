#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int dy[5] = {0, -1, 0, 1, 0};
const int dx[5] = {0, 0, -1, 0, 1};
const int INF = 0x3f3f3f3f;

int mt[310][310];	// false for safe, true for not safe
int bt[310][310];	// time she visit

void solve()
{
	int M;
	cin >> M;
	memset(mt, 0x3f, sizeof(mt));
	memset(bt, -1, sizeof(bt));

	for (int m = 0; m < M; m++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		for (int i = 0; i < 5; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny <= 302 && nx <= 302)
			{
				mt[y][x] = min(mt[y][x], t);
			}
		}
	}

	bt[0][0] = 0;
	if (bt[0][0] == mt[0][0])
	{
		cout << -1 << endl;
		return;
	}
	if (mt[0][0] == INF)
	{
		cout << 0 << endl;
		return;
	}

	queue<P> q;
	q.push(P(0, 0));
	while (!q.empty())
	{
		P p = q.front(); q.pop();
		int y = p.first, x = p.second;

		for (int i = 1; i < 5; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny > 302 || nx < 0 || nx > 302)
			{
				continue;
			}
			if (bt[y][x] == -1)
			{
				bt[ny][nx] = bt[y][x] + 1;
				if (mt[ny][nx] == INF)
				{
					cout << bt[ny][nx] << endl;
					return;
				}
				if (bt[ny][nx] < mt[ny][nx])
				{
					q.push(P(ny, nx));
				}
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
