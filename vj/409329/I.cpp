#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

const short dx[6] = {1, 0, 0, -1, 0, 0};
const short dy[6] = {0, 1, 0, 0, -1, 0};
const short dz[6] = {0, 0, 1, 0, 0, -1};

const short INF = 30000;

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

short d, h, w;
char maze[30][30][30];	// z, y, x

struct pos
{
	short z, y, x, t;
};

int bfs(short sz, short sy, short sx)
{
	queue<pos> q;
	q.push({sz, sy, sx, 0});

	while (q.size())
	{
		pos p = q.front(); q.pop();
		short z = p.z, y = p.y, x = p.x, t = p.t;
		//cout << "bfs(" << z << ", " << y << ", " << x << ")\n";
		
		if (maze[z][y][x] == 'E')
		{
			while (q.size()) q.pop();
			return t;
		}
		maze[z][y][x] = '#';
		for (short i = 0; i < 6; i++)
		{
			short nz = z + dz[i];
			short ny = y + dy[i];
			short nx = x + dx[i];
			if (nz < 0 || nz >= d || ny < 0 || ny >= h || nx < 0 || nx >= w || maze[nz][ny][nx] == '#')
			{
				continue;
			}
			q.push({nz, ny, nx, t + 1});
		}
	}
	while (q.size()) q.pop();
	return -1;
}

void solve()
{
	for (;;)
	{
		cin >> d >> h >> w;
		if (!d && !h && !w) return;

		short sz, sy, sx;
		for (short i = 0; i < d; i++)
		{
			for (short j = 0; j < h; j++)
			{
				for (short k = 0; k < w; k++)
				{
					maze[i][j][k] = gch();
					if (maze[i][j][k] == 'S')
					{
						sz = i, sy = j, sx = k;
					}
				}
			}
		}

		short ans = bfs(sz, sy, sx);
		if (ans == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << ans << " minutes(s)." << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
