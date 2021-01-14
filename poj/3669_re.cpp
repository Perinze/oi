#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int mt[303][303];
int vis[303][303];

int bfs()
{
	if (mt[0][0] == INF) return 0;
	if (mt[0][0] == 0) return -1;

	queue<P> que;
	que.push(P(0, 0));
	vis[0][0] = 0;
	while (!que.empty())
	{
		P p = que.front(); que.pop();
		int y = p.first, x = p.second, t = vis[y][x];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= 0 && ny <= 302 && nx >= 0 && nx <= 302 && vis[ny][nx] == -1 && t + 1 < mt[ny][nx])
			{
				if (mt[ny][nx] == INF)
				{
					return t + 1;
				}
				vis[ny][nx] = t + 1;
				que.push(P(ny, nx));
			}
		}
	}
	return -1;
}

void solve()
{
	int M;
	scanf("%d", &M);
	
	memset(mt, 0x3f, sizeof(mt));
	memset(vis, -1, sizeof(vis));
	for (int m = 0; m < M; m++)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		mt[y][x] = min(mt[y][x], t);
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > 302 || nx > 302)
			{
				continue;
			}
			mt[ny][nx] = min(mt[ny][nx], t);
		}
	}

	printf("%d\n", bfs());
}

int main()
{
	solve();
	return 0;
}
