#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

const int MAXV = 510;
const double INF = 0x7f7f7f7f7f7f7f7f;

double cost[MAXV][MAXV];
double mincost[MAXV];
bool used[MAXV];
double x[MAXV], y[MAXV];
int S, V;

void prim()
{
    memset(mincost, 0x7f, sizeof(mincost));
    memset(used, 0, sizeof(used));
    mincost[0] = 0.0;
    for (;;) {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; u++)
            mincost[u] = std::min(mincost[u], cost[v][u]);
    }
}

double dist(int u, int v)
{
    return sqrt((y[u] - y[v]) * (y[u] - y[v]) + (x[u] - x[v]) * (x[u] - x[v]));
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &S, &V);
        for (int i = 0; i < V; i++) {
            scanf("%lf%lf", x + i, y + i);
            for (int j = i - 1; j >= 0; j--)
                cost[i][j] = cost[j][i] = dist(i, j);
            cost[i][i] = INF;
        }
        prim();
        std::sort(mincost, mincost + V);
        printf("%.2f\n", mincost[V - S]);
    }
    return 0;
}