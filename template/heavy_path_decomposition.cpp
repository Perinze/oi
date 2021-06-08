int n;
vector<int> G[maxn];
int par[maxn];
int dep[maxn];
int siz[maxn];
int kid[maxn];
int rnk[maxn];
int top[maxn];
int id[maxn];
int root;

void dfsa(int v, int p)
{
    par[v] = p;
    dep[v] = dep[p] + 1;
    siz[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        dfsa(u, v);
        siz[v] += siz[u];
        if (siz[u] > siz[kid[v]])
            kid[v] = u;
    }
}

int cnt;
void dfsb(int v, int t)
{
    top[v] = t;
    id[v] = ++cnt;
    rnk[cnt] = v;
    if (!kid[v])
        return;
    dfsb(kid[v], t);

    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (u != kid[v] && u != par[v])
            dfsb(u, u);
    }
}

int lca(int v, int u)
{
    int fv = top[v], fu = top[u];
    while (fv != fu) {
        if (dep[fv] >= dep[fu]) {
            v = par[v], fv = top[v];
        } else {
            u = par[u], fu = top[u];
        }
    }
    if (id[v] <= id[u])
        return v;
    else
        return u;
}