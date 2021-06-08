#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
struct edge {
    int v, u;
};

int head[maxn];
int to[maxn * 2];
int nxt[maxn * 2];
int cnt; // 1-ordered

void add(int v, int u)
{
    ++cnt;
    to[cnt] = u;
    nxt[cnt] = head[v];
    head[v] = cnt;
}

int par[maxn][20];
int rnk[maxn];
int d[maxn];
int n, m;
int ans;

void init(int v)
{
    for (int i = 1; i < 20; i++)
        par[v][i] = par[par[v][i - 1]][i - 1];
}

void stdfs(int v, int p)
{
    rnk[v] = rnk[p] + 1;
    init(v);
    for (int i = head[v]; i; i = nxt[i]) {
        int u = to[i];
        if (u == p) continue;
        par[u][0] = v;
        stdfs(u, v);
    }
}

int query(int v, int t)
{
    for (int i = 0; i < 20; i++)
        if (t & (1 << i)) v = par[v][i];
    return v;
}

int lca(int v, int u)
{
    if (rnk[v] < rnk[u]) swap(v, u);
    v = query(v, rnk[v] - rnk[u]);
    if (v == u) return v;
    for (int i = 19; i >= 0; i--)
        if (par[v][i] != par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}

void dfs(int v, int p)
{
    for (int i = head[v]; i; i = nxt[i]) {
        int u = to[i];
        if (u == p) continue;
        dfs(u, v);
        if (d[u] == 0) ans += m;
        else if (d[u] == 1) ans += 1;
        d[v] += d[u];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int v, u;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &v, &u);
        add(v, u);
        add(u, v);
    }
    stdfs(1, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        d[v] += 1, d[u] += 1, d[lca(v, u)] -= 2;
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}