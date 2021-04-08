#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int n;
int r[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
int dp[MAXN][2];

void dfs(int v)
{
    if (vis[v]) return;
    dp[v][0] = 0;
    dp[v][1] = r[v];
    vis[v] = true;
    if (G[v].empty()) return;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (vis[u]) continue;
        dfs(u);
        dp[v][0] += max(dp[u][0], dp[u][1]);
        dp[v][1] += dp[u][0];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", r + i);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", max(dp[1][0], dp[1][1]));
    return 0;
}