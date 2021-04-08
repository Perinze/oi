#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAXV = 100010;
const int INF = 0x3f3f3f3f;
struct edge {
    int to, cost;
};
vector<edge> G[MAXV * 3];
int cnt[MAXV];
int d[MAXV * 3];
int V, M, C;

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d + 1, 0x3f, V * 3 * sizeof(int));
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &V, &M, &C);

        for (int i = 1; i <= V * 3; i++) {
            G[i].clear();
        }
        // 1-V vertex
        // V+1-V+V layer vertex
        // V+V+1-V+V+V reverse layer vertex
        
        // vertex to layer
        memset(cnt + 1, 0, V * sizeof(int));
        for (int i = 1; i <= V; i++) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
            G[i].push_back({V + x, 0});
            G[V * 2 + x].push_back({i, 0});
        }
        // layer to layer
        for (int i = 1; i < V; i++) {
            if (cnt[i] == 0 || cnt[i + 1] == 0) continue;
            G[V + i].push_back({V * 2 + i + 1, C});
            G[V + i + 1].push_back({V * 2 + i, C});
        }
        // extra edge
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dijkstra(1);
        printf("Case #%d: %d\n", cas, d[V] == INF ? -1 : d[V]);
    }
    return 0;
}