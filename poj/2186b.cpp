#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 10010;
vector<int> G[maxn];
vector<int> rG[maxn];
int dfn[maxn], low[maxn];
bool vis[maxn];
int n, m;
int scccnt;
int sccidx[maxn];
int sccsiz[maxn];
int cnt;

bool ins[maxn];
stack<int> stk;

void tarjan(int v)
{
    dfn[v] = low[v] = ++cnt;
    ins[v] = true;
    stk.push(v);
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (!dfn[u]) {
            tarjan(u);
            low[v] = min(low[v], low[u]);
        } else if (ins[u])
            low[v] = min(low[v], dfn[u]);
    }
    if (low[v] == dfn[v]) {
        ++scccnt;
        int u;
        do {
            u = stk.top();
            stk.pop();
            ins[u] = false;
            sccidx[u] = scccnt;
            sccsiz[scccnt]++;
        } while (u != v);
    }
}

void scc()
{
    for (int i = 0; i < n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i < n; i++) {
        clog << i << ": " << dfn[i] << " " << low[i] << " " << sccidx[i] << endl;
    }
}

void rdfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < rG[v].size(); i++) {
        int u = rG[v][i];
        if (!vis[u])
            rdfs(u);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        G[from - 1].push_back(to - 1);
        rG[to - 1].push_back(from - 1);
    }
    scc();
    int res = 0, far = 0;
    for (int i = 0; i < n; i++)
        if (sccidx[i] == 1) {
            res++;
            far = i;
        }
    //clog << far << endl;
    rdfs(far);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            res = 0;
            break;
        }
    }
    cout << res << endl;
    return 0;
}