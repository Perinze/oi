int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
int prv[MAXV];
int V;

void dijkstra(int s)
{
    memset(d, 0x3f, V * sizeof(int));
    memset(used, 0, V * sizeof(bool));
    memset(prv, -1, V * sizeof(int));
    d[s] = 0;
    for (;;)
    {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; u++)
        {
            if (d[u] > d[v] + cost[v][u])
            {
                d[u] = d[v] + cost[v][u];
                prv[u] = v;
            }
        }
    }
}

vector<int> get_path(int t)
{
    vector<int> path;
    for (; t != -1; t = prv[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}