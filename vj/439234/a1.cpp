#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 4e4 + 10;

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

int main()
{
    scanf("%d", &n);
    int v, u;
    //set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v, &u);
        if (v == -1 || u == -1) {
            root = (v == -1 ? u : v);
        } else {
            G[u].push_back(v);
            G[v].push_back(u);
            //s.insert(v);
            //s.insert(u);
        }
    }
    dfsa(root, 0);
    dfsb(root, root);
    /*
    for (auto v : s) {
        printf("%d par:%d dep:%d siz:%d kid:%d top:%d id:%d\n", v, par[v], dep[v], siz[v], kid[v], top[v], id[v]);
    }
    */
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &v, &u);
        int o = lca(v, u);
        //printf("%d\n", o);
        if (o == v) puts("1");
        else if (o == u) puts("2");
        else puts("0");
    }
    return 0;
}