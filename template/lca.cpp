int par[maxn][logmaxn];
int rnk[maxn];
bool vis[maxn];
vector<int> G[maxn];
int n, m;

void init(int v)
{
    for (int i = 1; i < logmaxn; i++) {
        par[v][i] = par[par[v][i - 1]][i - 1];
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
        par[u][0] = v;
        dfs(u, d + 1);
    }
}

int gpar(int v, int t)
{
    for (int i = 0; i < logmaxn; i++)
        if (t & (1 << i)) v = par[v][i];
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
        if (par[v][i] != par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}

// dfs order
int timestamp;
int in[maxn], out[maxn];
void dfs(int v, int p)
{
    par[v][0] = p;
    rnk[v] = rnk[p] + 1;
    in[v] = ++cnt;
    init(v);
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        dfs(u, v);
    }
    out[v] = cnt;
}

int lca(int v, int u)
{
    if (rnk[v] < rnk[u])
        swap(v, u);
    v = par(v, rnk[v] - rnk[u]);
    for (int i = logmaxn - 1; i >= 0; i--) {
        int tmp = par[v][i];
        if (!(in[tmp] <= in[u] && out[tmp] >= out[u]))
            v = tmp;
    }
    return par[v][0];
}