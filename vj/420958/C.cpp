#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXV = 1000, INF = 0x3f3f3f3f;

struct edge { int to, cost; };
vector<edge> G[MAXV];
int d[MAXV];
bool used[MAXV];
int V, E;

void dijkstra(int s)
{
    memset(d, 0, V * sizeof(int));
    memset(used, 0, V * sizeof(bool));
    d[s] = INF;
    for (;;)
    {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || d[u] > d[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        for (int j = 0; j < G[v].size(); j++)
        {
            int u = G[v][j].to, w = G[v][j].cost;
            d[u] = max(d[u], min(d[v], w));
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d%d", &V, &E);
        for (int j = 0; j < E; j++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dijkstra(0);
        printf("Scenario #%d:\n", i);
        printf("%d\n\n", d[V - 1]);
        for (int i = 0; i < V; i++) G[i].clear();
    }
    return 0;
}