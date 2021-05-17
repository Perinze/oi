#include <cstdio>
#include <cstring>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;
typedef pair<int, int> P;
int par[maxn];
int rnk[maxn];
bool vis[maxn];
int root;
vector<int> G[maxn];
int n, m;

void dfs(int v, int d)
{
    vis[v] = true;
    rnk[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (vis[u]) continue;
        par[u] = v;
        dfs(u, d + 1);
    }
}

int lca(int v, int u)
{
    int res = 2;
    if (rnk[v] < rnk[u]) {
        res = 1;
        swap(v, u);
    }
    for (int crt = par[v]; crt; crt = par[crt]) {
        if (crt == u) {
            return res;
        }
    }
    return 0;
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
        printf("%d -> %d\n", v, par[v]);
    */
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        printf("%d\n", lca(v, u));
    }
    return 0;
}