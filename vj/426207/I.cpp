#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
vector<P> G[MAXN];
int deg[MAXN];
int f[MAXN];
int g[MAXN];
bool vis[MAXN];
int n;

void dfs(int v)
{
    vis[v] = true;
    f[v] = 0;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int u = G[v][i].first, w = G[v][i].second;
        if (vis[u]) continue;
        dfs(u);
        if (deg[u] == 1)
            f[v] += w;
        else
            f[v] += min(f[u], w);
    }
}

void redfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int u = G[v][i].first, w = G[v][i].second;
        if (vis[u]) continue;
        if (deg[v] == 1)
            g[u] = f[u] + w;
        else
            g[u] = f[u] + min(g[v] - min(w, f[u]), w);
        redfs(u);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= MAXN; i++)
            G[i].clear();
        scanf("%d", &n);
        for (int i = 1; i <= n - 1; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(P(v, w));
            G[v].push_back(P(u, w));
            deg[u]++;
            deg[v]++;
        }
        memset(vis, 0, sizeof(vis));
        dfs(1);
        //for (int i = 1; i <= n; i++)
            //printf("f[%d]=%d\n", i, f[i]);
        memset(vis, 0, sizeof(vis));
        g[1] = f[1];
        redfs(1);
        //for (int i = 1; i <= n; i++)
            //printf("g[%d]=%d\n", i, g[i]);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, g[i]);
        printf("%d\n", ans);
    }
    return 0;
}