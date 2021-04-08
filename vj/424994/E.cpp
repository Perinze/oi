#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110, MAXL = 1010;
int n, m, l;
int t[MAXN], v[MAXN];
int dp[MAXN][MAXL];

int dfs(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (j <= 0) return 0;
    if (i > n) return 0;
    int res = dfs(i + 1, j);
    if (j >= t[i]) res = max(res, dfs(i + 1, j - t[i]) + v[i]);
    return dp[i][j] = res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &l);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", t + i, v + i);
            s += v[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(1, l);
        printf("%d\n", ans);
    }
    return 0;
}