// bellman-ford O(VE)
// d[i] = min{d[j] + cost[j][i]}
struct edge { int from, to, cost; };

edge es[MAXE];

int d[MAXV];
int V, E;

bool shortest_path(int s) // true for negative loop
{
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    for (int j = 0; j < V; j++) // if no negative loop, this loop runs at most V - 1 times
    {
        bool update = false;
        for (int i = 0; i < E; i++)
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
                if (j == V - 1) return true;
            }
        }
        if (!update) break;
    }
    return false;
}