#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;

vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool vis[maxn];
int cmp[maxn];
int n, m;

inline void addedge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    vis[v] = true;
    for (int u : G[v])
    {
        if (!vis[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    vis[v] = true;
    cmp[v] = k;
    for (int u : rG[v])
    {
        if (!vis[u])
            rdfs(u, k);
    }
}

int scc()
{
    memset(vis, 0, sizeof(vis));
    vs.clear();
    for (int v = 0; v < n; v++)
    {
        if (!vis[v]) dfs(v);
    }
    memset(vis, 0, sizeof(vis));
    int k = 0;
    for (auto ite = vs.rbegin(); ite != vs.rend(); ite++)
    {
        if (!vis[*ite])
            rdfs(*ite, k++);
    }
    return k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        addedge(from - 1, to - 1);
    }
    int n_ = scc();
    int u = 0, res = 0;
    for (int v = 0; v < n; v++)
    {
        if (cmp[v] == n_ - 1)
        {
            u = v;
            res++;
        }
    }
    memset(vis, 0, sizeof(vis));
    rdfs(u, 0);
    for (int v = 0; v < n; v++)
    {
        if (!vis[v])
        {
            res = 0;
            break;
        }
    }
    cout << res << endl;
    return 0;
}