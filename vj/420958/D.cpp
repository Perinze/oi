#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1000;

struct edge { int to, cost; };
typedef pair<int, int> P;

int V, E, X;
vector<edge> G[MAXV];
int d[MAXV][MAXV];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, s));
    d[s][s] = 0;

    while (!q.empty())
    {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[s][v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[s][e.to] > d[s][v] + e.cost)
            {
                d[s][e.to] = d[s][v] + e.cost;
                q.push(P(d[s][e.to], e.to));
            }
        }
    }
}


int main()
{
    scanf("%d%d%d", &V, &E, &X);
    X--;
    for (int e = 0; e < E; e++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        G[u].push_back({v, w});
    }
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < V; i++) dijkstra(i);
    int ans = 0;
    for (int i = 0; i < V; i++)
        ans = max(ans, d[i][X] + d[X][i]);
    printf("%d\n", ans);
    return 0;
}