struct edge { int to, cost; };
typedef pair<int, int> P;

int V;
vector<edge> G[MAXV];
int d[MAXV];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d, 0x3f, V * sizeof(int));
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
