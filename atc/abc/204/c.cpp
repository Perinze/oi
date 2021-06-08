#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2010;
int n, m;

vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool vis[maxn];
int cmp[maxn];
int siz[maxn];
vector<int> sccG[maxn];
vector<int> sccrG[maxn];

inline void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    vis[v] = true;
    for (int u : G[v]) {
        if (!vis[u]) dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    vis[v] = true;
    cmp[v] = k;
    siz[k]++;
    for (int u : rG[v]) {
        if (!vis[u]) rdfs(u, k);
    }
}

int scc()
{
    memset(vis, 0, sizeof(vis));
    vs.clear();
    for (int v = 0; v < n; v++) {
        if (!vis[v]) dfs(v);
    }
    memset(vis, 0, sizeof(vis));
    memset(siz, 0, sizeof(siz));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!vis[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

ll sccdfs(int v, ll x)
{
    ll cnt = 0;
    vis[v] = true;
    cnt += siz[v] * x;
    for (int u : sccG[v]) {
        if (!vis[u]) cnt += sccdfs(u, x);
    }
    return cnt;
}

/*
int sccrdfs(int v)
{
    int cnt = 1;
    vis[v] = true;
    for (int u : sccrG[v]) {
        if (!vis[u]) cnt += sccrdfs(u);
    }
    return cnt;
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        add_edge(a, b);
    }
    int scccnt = scc();
    ll ans = 0;
    /*
    for (int k = 0; k < scccnt; k++) {
        ans += siz[k] * siz[k];
    }
    */
    for (int v = 0; v < n; v++) {
        for (int u : G[v]) {
            sccG[cmp[v]].push_back(cmp[u]);
            sccrG[cmp[u]].push_back(cmp[v]);
        }
    }
    for (int k = 0; k < scccnt; k++) {
        memset(vis, 0, sizeof(vis));
        ans += sccdfs(k, siz[k]);
    }
    cout << ans << endl;
    return 0;
}