#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 100010;
typedef long long ll;

struct edge {
    int u, v, w;
    bool operator<(edge &s) const {
        return w < s.w;
    }
} es[MAX];
int E;

int par[MAX], rnk[MAX], siz[MAX];

void init()
{
    for (int i = 1; i <= E + 1; i++) {
        par[i] = i;
        rnk[i] = 0;
        siz[i] = 1;
    }
}

int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
        siz[y] += siz[x];
    } else {
        par[y] = x;
        siz[x] += siz[y];
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

ll kruskal()
{
    init();
    std::sort(es, es + E);
    ll res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        int u = find(e.u);
        int v = find(e.v);
        res += e.w;
        res += (ll)(siz[u] * siz[v] - 1) * (e.w + 1);
        unite(u, v);
    }
    return res;
}

int main()
{
    scanf("%d", &E);
    E--;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        es[i] = {u, v, w};
    }
    printf("%lld\n", kruskal());
    return 0;
}