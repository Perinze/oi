#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

typedef long long ll;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};
const int INF = 20;

int W, H;
int map[20][20];
int vis[20][20];	// present to be hit here
int sy, sx, ty, tx;

char gch()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '3') return c;
	}
	return '?';
}

int ans;
void dfs(int y, int x, int t)
{
	if (t >= 10) return;
	//cout << "dfs(" << y << ", " << x << ")" << endl;
	/*
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == y && j == x) cout << '@' << ' ';
			else cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	int cy = y, cx = x;
	for (int i = 0; i < 4; i++)
	{
		y = cy, x = cx;

		if (map[y + dy[i]][x + dx[i]] == 1) continue;

		bool goal = false;
		//cout << "moving" << endl;
		//cout << y << ", " << x << endl;
		while (y >= 0 && y < H && x >= 0 && x < W && map[y][x] == 0)
		{
			if (y == ty && x == tx)
			{
				//cout << "goal" << endl;
				ans = min(ans, t + 1);
				goal = true;
				break;
			}
			y += dy[i];
			x += dx[i];
			//cout << y << ", " << x << endl;
		}
		//cout << "stoped" << endl;
		if (goal) continue;
		if (y < 0 || y >= H || x < 0 || x >= W) 
		{
			continue;
		}
		if (map[y][x] == 1)
		{
			int ry = y, rx = x;
			map[ry][rx] = 0;
			y -= dy[i];
			x -= dx[i];
			dfs(y, x, t + 1);
			map[ry][rx] = 1;
		}
	}
}

void solve()
{
	for (;;)
	{
		fill(vis[0], vis[0] + 20 * 20, false);
		ans = INF;
		cin >> W >> H;
		if (W == 0 && H == 0) return;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				int c; cin >> c;
				map[y][x] = c;
				if (c == 2)
				{
					map[y][x] = 0;
					sy = y, sx = x;
				}
				if (c == 3)
				{
					map[y][x] = 0;
					ty = y, tx = x;
				}
			}
		}
		//cout << sy << ' ' << sx << ' ' << ty << ' ' << tx << endl;
		dfs(sy, sx, 0);
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}

int main()
{
	solve();
	return 0;
}
