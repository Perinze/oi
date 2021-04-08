#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1510;
vector<int> kid[MAXN];
int n;
int len[MAXN];
bool iskid[MAXN];
int dp[MAXN][2];
int root;

void dfs(int v)
{
    dp[v][0] = 0;
    dp[v][1] = 1;
    if (!len[v]) return;
    for (int i = 0; i < len[v]; i++) {
        int u = kid[v][i];
        dfs(u);
        dp[v][0] += dp[u][1];
        dp[v][1] += min(dp[u][0], dp[u][1]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        scanf("%d", len + v);
        for (int j = 0; j < len[v]; j++) {
            int u;
            scanf("%d", &u);
            kid[v].push_back(u);
            iskid[u] = true;
        }
    }
    root = 0;
    while (iskid[root]) root++;
    //printf("%d\n", root);
    dfs(root);
    //for (int i = 0; i < n; i++)
        //printf("%d %d\n", dp[i][0], dp[i][1]);
    int ans = min(dp[root][0], dp[root][1]);
    printf("%d\n", ans);
    return 0;
}