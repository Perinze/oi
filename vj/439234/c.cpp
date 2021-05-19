#include <cstdio>
#include <algorithm>

typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 3e5 + 10;
const int inf = 0x3f3f3f3f;

namespace uset {
    int par[maxn];
    void init(int n)
    {
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int x)
    {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return;
        par[x] = y;
    }
}

struct edge {
    int v, u, w;
    bool operator <(const edge &s) { return w < s.w; }
} es[maxm];
bool vis[maxm];
int n, m;

int head[maxn];
int to[maxm * 2];
int cost[maxm * 2];
int nxt[maxm * 2];
int cnt; // 1-ordered

void add(int v, int u, int w)
{
    ++cnt;
    to[cnt] = u;
    cost[cnt] = w;
    nxt[cnt] = head[v];
    head[v] = cnt;
}

int _par[maxn][20];
int _rnk[maxn];
int mx[maxn][20];
int smx[maxn][20];

void dfs(int v, int p)
{
    _rnk[v] = _rnk[p] + 1;
    _par[v][0] = p;
    for (int i = head[v]; i; i = nxt[i]) {
        if (to[i] == p) continue;
        mx[to[i]][0] = cost[i];
        smx[to[i]][0] = -inf;
        dfs(to[i], v);
    }
}

void init()
{
    for (int i = 1; i < 20; i++) {
        for (int v = 1; v <= n; v++) {
            _par[v][i] = _par[_par[v][i - 1]][i - 1];
            mx[v][i] = std::max(mx[v][i - 1], mx[_par[v][i - 1]][i - 1]);
            smx[v][i] = std::max(smx[v][i - 1], smx[_par[v][i - 1]][i - 1]);
            if (mx[v][i - 1] < mx[_par[v][i - 1]][i - 1])
                smx[v][i] = std::max(smx[v][i], mx[v][i - 1]);
            else if (mx[v][i - 1] > mx[_par[v][i - 1]][i - 1])
                smx[v][i] = std::max(smx[v][i], mx[_par[v][i - 1]][i - 1]);
        }
    }
}

int par(int v, int t)
{
    for (int i = 0; i < 20; i++)
        if (t & (1 << i)) v = _par[v][i];
    return v;
}

int lca(int v, int u)
{
    if (v == u) return v;
    if (_rnk[v] < _rnk[u]) std::swap(v, u);
    v = par(v, _rnk[v] - _rnk[u]);
    if (v == u) return v;
    for (int i = 19; i >= 0; i--)
        if (_par[v][i] != _par[u][i])
            v = _par[v][i], u = _par[u][i];
    return _par[v][0];
}

int query(int v, int _lca, int w)
{
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
        if (_rnk[_par[v][i]] >= _rnk[_lca]) {
            if (mx[v][i] < w)
                ans = std::max(ans, mx[v][i]);
            else
                ans = std::max(ans, smx[v][i]);
            v = _par[v][i];
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        es[i] = {v, u, w};
    }
    std::sort(es, es + m);
    ll mst = 0;
    uset::init(n);
    for (int i = 0; i < m; i++) {
        int v = uset::find(es[i].v), u = uset::find(es[i].u);
        if (v != u) {
            mst += es[i].w;
            uset::unite(v, u);
            vis[i] = true;
            add(es[i].v, es[i].u, es[i].w);
            add(es[i].u, es[i].v, es[i].w);
        }
    }
    dfs(1, 0);
    init();
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            int v = es[i].v, u = es[i].u, w = es[i].w;
            int _lca = lca(v, u);
            int wv = query(v, _lca, w), wu = query(u, _lca, w);
            ans = std::min(ans, mst - std::max(wv, wu) + w);
        }
    }
    printf("%lld\n", ans);
    return 0;
}