#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110, MAXL = 1010;
<<<<<<< HEAD
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
=======
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXL];
int N, M, l;
int t[MAXN], v[MAXN];
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
<<<<<<< HEAD
        scanf("%d%d%d", &n, &m, &l);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", t + i, v + i);
            s += v[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(1, l);
        printf("%d\n", ans);
=======
        scanf("%d%d%d", &N, &M, &l);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", t + i, v + i);
        for (int i = 0; i <= l; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= M; i++)
            for (int j = 0; j <= l; j++)
                dp[i][j] = -1;

        for (int i = 1; i <= N; i++) {
            for (int j = l; j >= t[i]; j--) {
                for (int k = M; k > 0; k--) {
                    if (dp[k - 1][j - t[i]] >= 0) dp[k][j] = max(dp[k][j], dp[k - 1][j - t[i]] + v[i]);
                }
            }
        }
        if (dp[M][l] >= 0) printf("%d\n", dp[M][l]);
        else printf("0\n");
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
    }
    return 0;
}