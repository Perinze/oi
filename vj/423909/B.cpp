#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXV = 110;
const double INF = 0x4343434343434343;

double cost[MAXV][MAXV];
double mincost[MAXV];
bool used[MAXV];
int V;
double x[MAXV], y[MAXV];

double prim() {
    memset(mincost, 0x43, sizeof(mincost));
    memset(used, 0, sizeof(used));
    mincost[0] = 0;
    double res = 0;

    for (;;) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        for (int u = 0; u < V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

double dist(int u, int v)
{
    double d = sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
    if (d < 10.0 || d > 1000.0) return INF;
    else return d;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &V);
        memset(cost, 0x43, sizeof(cost));
        for (int i = 0; i < V; i++) {
            scanf("%lf%lf", x + i, y + i);
            for (int j = i - 1; j >= 0; j--)
                cost[i][j] = cost[j][i] = dist(i, j);
        }
        double ans = prim();
        if (ans > 100000.0) printf("oh!\n");
        else printf("%.1f\n", ans * 100.0);
    }
    return 0;
}