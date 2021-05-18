int __par[maxn][logmaxn];
int rnk[maxn];
bool vis[maxn];
vector<int> G[maxn];
int n, m;

void init(int v)
{
    for (int i = 1; i < logmaxn; i++) {
        if (rnk[i] < (1 << i)) break;
        __par[v][i] = __par[__par[v][i - 1]][i - 1];
    }
}

void dfs(int v, int d)
{
    vis[v] = true;
    rnk[v] = d;
    init(v);
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (vis[u]) continue;
        __par[u][0] = v;
        dfs(u, d + 1);
    }
}

int par(int v, int t)
{
    for (int i = 0; i < logmaxn; i++)
        if (t & (1 << i)) v = __par[v][i];
    return v;
}

int lca(int v, int u)
{
    // suppose rnk[v] > rnk[u]
    if (rnk[v] < rnk[u])
        swap(v, u);
    v = par(v, rnk[v] - rnk[u]);
    if (v == u) return v;
    for (int i = logmaxn - 1; i >= 0; i--)
        if (__par[v][i] != __par[u][i])
            v = __par[v][i], u = __par[u][i];
    return __par[v][0];
}