#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int MAXV = 110;
const int INF = 0x3f3f3f3f;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int cost[MAXV][MAXV];
int mincost[MAXV];
bool used[MAXV];
int V;
int id[60][60];
int x[MAXV], y[MAXV];
int w, h;

char gch()
{
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '#' || c == ' ' || c == 'A' || c == 'S')
            return c;
    }
}

int d[60][60];
void bfs(int v)
{
    memset(d, -1, sizeof(d));
    d[y[v]][x[v]] = 0;
    queue<P> q;
    q.push(P(y[v], x[v]));
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        int cy = p.first;
        int cx = p.second;
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= h) continue;
            if (nx < 0 || nx >= w) continue;
            if (d[ny][nx] != -1) continue;
            if (id[ny][nx] == -1) continue;
            d[ny][nx] = d[cy][cx] + 1; 
            q.push(P(ny, nx));
            if (id[ny][nx] >= 0)
                cost[id[ny][nx]][v] = cost[v][id[ny][nx]] = d[ny][nx];
        }
    }
    cost[v][v] = INF;
}

int prim()
{
    memset(mincost, 0x3f, sizeof(mincost));
    memset(used, 0, sizeof(used));
    mincost[0] = 0;
    int res = 0;

    for (;;) {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        for (int u = 0; u < V; u++)
            mincost[u] = min(mincost[u], cost[v][u]);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &w, &h);
        char wdnmd;
        while ((wdnmd = getchar()) == ' ');
        V = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c = gch();
                if (c == 'A' || c == 'S') {
                    id[i][j] = V;
                    y[V] = i;
                    x[V] = j;
                    V++;
                } else if (c == '#')
                    id[i][j] = -1;
                else if (c == ' ')
                    id[i][j] = -2;
                else for (;;);
            }
        }
        for (int i = 0; i < V; i++) bfs(i);
        printf("%d\n", prim());
    }
    return 0;
}