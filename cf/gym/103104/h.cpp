#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int maxn = 310, maxm = 10010;
bitset<maxn> out[maxn], in[maxn];
vector<int> G[maxn];
vector<int> Gold[maxn];
int d[maxn];
int n, m;

namespace uset {

int par[maxn];

inline void init()
{
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

inline int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

inline void unite(int x, int y)
{
    x = find(x), y = find(y);
    par[x] = y;
}

inline bool same(int x, int y)
{
    return find(x) == find(y);
}

}

void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(d, 0x3f, sizeof(d));
    int s = uset::find(1);
    d[s] = 0;
    q.push(pii(0, s));
    while (!q.empty()) {
        pii p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int u : G[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(pii(d[u], u));
            }
        }
    }
    for (int v = 1; v <= n; v++) {
        d[v] = d[uset::find(v)];
        if (d[v] >= 0x3f3f3f3f) d[v] = -1;
    }
}

void init()
{
    for (int v = 1; v <= n; v++) {
        out[v].reset();
        in[v].reset();
        G[v].clear();
    }
    for (int v = 1; v <= n; v++) {
        int fv = uset::find(v);
        for (int u : Gold[v]) {
            int fu = uset::find(u);
            if (fv == fu) continue;
            out[fv][fu] = 1;
            in[fu][fv] = 1;
        }
    }
    for (int v = 1; v <= n; v++) {
        if (uset::find(v) != v) continue;
        for (int u = 1; u <= n; u++) {
            if (out[v][u]) {
                G[v].push_back(u);
            }
        }
    }
}

bool merge()
{
    for (int v = 1; v <= n; v++) {
        if (uset::find(v) != v) continue;
        for (int u : G[v]) {
            bitset<maxn> tmp = out[u] & in[v];
            if (tmp.any()) {
                int w = 0;
                for (int j = 1; j <= n; j++) {
                    if (tmp[j]) {
                        w = j;
                        break;
                    }
                }
                if (w) {
                    uset::unite(v, u);
                    uset::unite(v, w);
                    return true;
                }
            }
            if (out[v][u] && in[v][u]) {
                uset::unite(v, u);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    uset::init();
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        Gold[from].push_back(to);
    }
    do {
        init();
    } while(merge());
    dijkstra();
    for (int v = 1; v <= n; v++) {
        cout << d[v] << ' ';
        //cout << d[uset::find(v)] << ' ';
    }
    cout << endl;
    return 0;
}