#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXV = 310;
const int INF = 0x3f3f3f3f;
int cost[MAXV][MAXV];
int mincost[MAXV];
bool used[MAXV];
int V;

int prim()
{
    memset(mincost, 0x3f, sizeof(mincost));
    mincost[0] = 0; 
    int res = 0;
    for (;;) {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        if (v == -1) break;
        res += mincost[v];
        used[v] = true;
        for (int u = 0; u < V; u++) {
            mincost[u] = std::min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

int main()
{
    scanf("%d", &V); V++;
    for (int i = 1; i < V; i++) {
        scanf("%d", cost[0] + i);
        cost[i][0] = cost[0][i];
    }
    cost[0][0] = INF;
    for (int i = 1; i < V; i++)
        for (int j = 1; j < V; j++) {
            scanf("%d", cost[i] + j);
            if (i == j) cost[i][j] = INF;
        }
    printf("%d\n", prim());
    return 0;
}