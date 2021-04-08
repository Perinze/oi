#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 110;

int cost[MAXV][MAXV];
int mincost[MAXV];
bool used[MAXV];
int V;

int prim() {
    memset(mincost, 0x3f, sizeof(mincost));
    memset(used, 0, sizeof(used));
    mincost[0] = 0;
    int res = 0;

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

int main()
{
    while (~scanf("%d", &V)) {
        if (V == 0) break;
        memset(cost, 0x3f, sizeof(cost));
        for (int i = 0; i < V * (V - 1) / 2; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            cost[u][v] = cost[v][u] = w;
        }
        printf("%d\n", prim());
    }
    return 0;
}