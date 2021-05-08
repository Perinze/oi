#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
void init(int);
int find(int);
void unite(int, int);
bool same(int, int);
//int count();

typedef pair<int, int> P;
const int maxn = 400010, maxm = 200010;
int n, m, k;
vector<int> G[maxn];
int tar[maxn];
bool dead[maxn];
int ans[maxn];

int par[maxn], rnk[maxn];
bool vis[maxn];
int cnt;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", tar + i);
        dead[tar[i]] = true;
    }

    init(n);
    for (int v = 0; v < n; v++) {
        if (dead[v]) continue;
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            if (dead[u]) continue;
            unite(v, u);
        }
    }
    ans[k] = cnt - k;
    for (int i = k - 1; i >= 0; i--) {
        int v = tar[i];
        dead[v] = false;
        for (int j = 0; j < G[v].size(); j++) {
            int u = G[v][j];
            if (!dead[u])
                unite(v, u);
        }
        ans[i] = cnt - i;
    }
    for (int i = 0; i <= k; i++)
        printf("%d\n", ans[i]);
    return 0;
}

void init(int n)
{
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
    cnt = n;
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

    if (rnk[x] < rnk[y])
        par[x] = y;
    else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
    cnt--;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

/*
int count()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!dead[i])
            vis[find(i)] = true;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (vis[i]) res++;
    return res;
}
*/