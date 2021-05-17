#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

namespace i {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s= 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') s = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        return x * s;
    }
}

const int maxn = 5e5 + 10, logmaxn = 21;
int __par[maxn][logmaxn];
int rnk[maxn];
vector<int> G[maxn];
int n, m;

inline void init(int v)
{
    for (int i = 1; i < logmaxn; i++) {
        __par[v][i] = __par[__par[v][i - 1]][i - 1];
    }
}

void dfs(int v, int p)
{
    rnk[v] = rnk[p] + 1;
    init(v);
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        __par[u][0] = v;
        dfs(u, v);
    }
}

inline int par(int v, int t)
{
    for (int i = 0; i < logmaxn; i++)
        if (t & (1 << i)) v = __par[v][i];
    return v;
}

int lca(int v, int u)
{
    if (v == u) return v;
    if (rnk[v] < rnk[u])
        swap(v, u);
    v = par(v, rnk[v] - rnk[u]);
    if (v == u) return v;
    for (int i = logmaxn - 1; i >= 0; i--)
        if (__par[v][i] != __par[u][i])
            v = __par[v][i], u = __par[u][i];
    return __par[v][0];
}

int main()
{
    n = i::read<int>(), m = i::read<int>();
    for (int i = 0; i < n - 1; i++) {
        int v = i::read<int>();
        int u = i::read<int>();
        G[v].push_back(u);
        G[u].push_back(v);
    }
    rnk[0] = -1;
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        int a = i::read<int>();
        int b = i::read<int>();
        int c = i::read<int>();
        int ab = lca(a, b);
        int bc = lca(b, c);
        int ca = lca(c, a);
        int res;
        if (ab == bc) res = ca;
        else if (bc == ca) res = ab;
        else res = bc;
        printf("%d %d\n", res, rnk[a] + rnk[b] + rnk[c] - rnk[ab] - rnk[bc] - rnk[ca]);
    }
    return 0;
}