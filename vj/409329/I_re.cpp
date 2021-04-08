#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int dx[6] = {1, 0, 0, -1, 0, 0};
const int dy[6] = {0, 1, 0, 0, -1, 0};
const int dz[6] = {0, 0, 1, 0, 0, -1};

const int INF = 10000000;

char gch()
{
	char c;
	while (cin.get(c))
	{
		if (c == 'S' || c == 'E' || c == '#' || c == '.')
		{
			return c;
		}
	}
	return '?';
}

int d, h, w;
char maze[40][40][40];	// z, y, x
int tt[40][40][40];

struct pos
{
	int z, y, x;
};

int bfs(int sz, int sy, int sx)
{
	queue<pos> q;
	q.push({sz, sy, sx});
	memset(tt, -1, sizeof(tt));
	tt[sz][sy][sx] = 0;

	while (!q.empty())
	{
		pos p = q.front(); q.pop();
		int z = p.z, y = p.y, x = p.x, t = tt[z][y][x];
		//cout << "bfs(" << z << ", " << y << ", " << x << ")\n";
		
		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || nz >= d || ny < 0 || ny >= h || nx < 0 || nx >= w || maze[nz][ny][nx] == '#' || tt[nz][ny][nx] != -1)
			{
				continue;
			}
			if (maze[nz][ny][nx] == 'E')
			{
				return t + 1;
			}
			tt[nz][ny][nx] = t + 1;
			q.push({nz, ny, nx});
		}
	}
	return -1;
}

void solve()
{
	for (;;)
	{
		cin >> d >> h >> w;
		if (!d && !h && !w) return;

		int sz, sy, sx;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					maze[i][j][k] = gch();
					if (maze[i][j][k] == 'S')
					{
						sz = i, sy = j, sx = k;
					}
				}
			}
		}

		int ans = bfs(sz, sy, sx);
		if (ans == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << ans << " minute(s)." << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
