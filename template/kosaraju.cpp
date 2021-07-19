vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool vis[maxn];
int scc[maxn], siz[maxn], scccnt;

void dfs(int u)
{
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) dfs(v);
    }
    vs.push_back(u);
}

void rdfs(int u, int k)
{
    vis[u] = true;
    scc[u] = scccnt;
    for (int v : rG[u]) {
        if (!vis[v]) rdfs(v, k);
    }
}

void kosaraju()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    memset(vis, 0, sizeof(vis));
    scccnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[vs[i]]) rdfs(vs[i], scccnt++);
    }
}