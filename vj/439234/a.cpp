#include <cstdio>
#include <cstring>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 4e4 + 10;
const int logmaxn = 20;
typedef pair<int, int> P;
int _par[maxn][logmaxn];
int rnk[maxn];
bool vis[maxn];
int root;
vector<int> G[maxn];
int n, m;

void init(int v)
{
    for (int i = 1; i <= logmaxn; i++) {
        if (rnk[v] < (1 << i)) break;
        _par[v][i] = _par[_par[v][i - 1]][i - 1];
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
        _par[u][0] = v;
        dfs(u, d + 1);
    }
}

int par(int v, int t)
{
    for (int i = 0; i < logmaxn; i++)
        if (t & (1 << i)) v = _par[v][i];
    return v;
}

int lca(int v, int u)
{
    if (rnk[v] < rnk[u])
        swap(v, u);
    v = par(v, rnk[v] - rnk[u]);
    if (v == u) return v;
    for (int i = logmaxn - 1; i >= 0; i--)
        if (_par[v][i] != _par[u][i])
            v = _par[v][i], u = _par[u][i];
    return _par[v][0];
}

int main()
{
    //set<int> G;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        if (v == -1 || u == -1) {
            root = (v == -1) ? u : v;
        } else {
            //G.insert(v);
            //G.insert(u);
            G[v].push_back(u);
            G[u].push_back(v);
        }
    }
    dfs(root, 0);
    /*
    for (auto v : G)
        printf("%d -> %d\n", v, _par[v]);
    */
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        int res = lca(v, u);
        if (res == v) puts("1");
        else if (res == u) puts("2");
        else puts("0");
    }
    return 0;
}