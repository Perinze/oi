#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXV = 760;
const double INF = 0x7f7f7f7f7f7f7f7f;
double y[MAXV], x[MAXV];
double cost[MAXV][MAXV];
double mincost[MAXV];
bool used[MAXV];
int prev[MAXV];
int V, M;

double dist(int u, int v)
{
    return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

void prim()
{
    memset(mincost, 0x7f, sizeof(mincost));
    mincost[0] = 0;
    for (;;) {
        int v = -1;
        for (int u = 1; u <= V; u++)
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        if (prev[v] && cost[prev[v]][v]) printf("%d %d\n", prev[v], v);
        if (v == -1) break;
        used[v] = true;
        for (int u = 1; u <= V; u++) {
            if (mincost[u] > cost[v][u]) {
                mincost[u] = cost[v][u];
                prev[u] = v;
            }
        }
    }
}

int main()
{
    scanf("%d", &V);
    for (int i = 1; i <= V; i++) {
        scanf("%lf%lf", x + i, y + i);
        for (int j = i - 1; j > 0; j--)
            cost[i][j] = cost[j][i] = dist(i, j);
        cost[i][i] = INF;
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        cost[u][v] = cost[v][u] = 0.0;
    }
    prim();
    return 0;
}