#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

typedef long long ll;
int W, H;
int ans = 0;
char map[20][20];
bool vis[20][20];

char gch()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == '.' || c == '#' || c == '@') return c;
	}
	return '?';
}

void dfs(int y, int x)
{
	//cout << "dfs(" << y << ',' << x << ") ";
	if (y < 0 || y >= H)
	{
		//cout << 1 << endl;
		return;
	}
	if (x < 0 || x >= W)
	{
		//cout << 2 << endl;
		return;
	}
	if (map[y][x] == '#')
	{
		//cout << 3 << endl;
		return;
	}
	if (vis[y][x])
	{
		//cout << 3 << endl;
		return;
	
	//cout << "visit" << endl;
	vis[y][x] = true;
	ans++;
	for (int i = 0; i < 4; i++)
	{
		dfs(y + dy[i], x + dx[i]);
	}
}

void solve()
{
	for (;;)
	{
		cin >> W >> H;
		if (W == 0 && H == 0) return;

		ans = 0;
		fill(vis[0], vis[0] + 20 * 20, false);
		int sy, sx;

		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				char c = gch();
				if (c == '.')
					map[y][x] = '.';
				else if (c == '#')
					map[y][x] = '#';
				else if (c == '@')
				{
					map[y][x] = '.';
					sy = y, sx = x;
				}
			}
		}
		dfs(sy, sx);
		cout << ans << endl;
	}
}

int main()
{
	solve();
	return 0;
}
