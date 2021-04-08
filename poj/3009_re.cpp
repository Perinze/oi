#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};
const int INF = 11;

int W, H;
int ans;
int map[20][20];

void dfs(int y, int x, int t)
{
	if (t > 9) return;
	
	for (int i = 0; i < 4; i++)
	{
		if (map[y + dy[i]][x + dx[i]] == 1) continue;

		int cy = y, cx = x;
		while (cy >= 0 && cy < H && cx >= 0 && cx < W && map[cy][cx] == 0)
		{
			cy += dy[i];
			cx += dx[i];
		}

		if (cy < 0 || cy >= H || cx < 0 || cx >= W)
		{
			continue;
		}

		if (map[cy][cx] == 3)
		{
			ans = min(ans, t + 1);
			break;
		}

		if (map[cy][cx] == 1)
		{
			int ry = cy, rx = cx;
			map[ry][rx] = 0;
			cy -= dy[i];
			cx -= dx[i];
			dfs(cy, cx, t + 1);
			map[ry][rx] = 1;
		}
	}
}

void solve()
{
	for (;;)
	{
		cin >> W >> H;
		if (W == 0 && H == 0) return;

		ans = INF;
		int sy, sx;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 2)
				{
					sy = i, sx = j;
					map[i][j] = 0;
				}
			}
		}

		dfs(sy, sx, 0);
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
