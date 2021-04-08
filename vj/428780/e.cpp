#include <cstdio>
#include <vector>
using namespace std;

#define maxn 1510

int n;
int dp[maxn][2];
int deg[maxn];
vector<int> G[maxn];
bool vis[maxn];

void dfs(int v)
{
    vis[v] = true;
    dp[v][1] = 1;
    for (int i = 0; i < deg[v]; i++) {
        int u = G[v][i];
        if (!vis[u]) dfs(u);
        dp[v][0] += dp[u][1];
        dp[v][1] += min(dp[u][0], dp[u][1]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, k;
        scanf("%d%d", &x, &k);
        deg[x] = k;
        for (int j = 0; j < k; j++) {
            int t;
            scanf("%d", &t);
            G[x].push_back(t);
        }
    }
    dfs(0);
    printf("%d\n", min(dp[0][0], dp[0][1]));
    return 0;
}