#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 410;
const int INF = 0x3f3f3f3f;
int n;
int a[MAXN];
int dp[2][MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i + n] = a[i];
        a[i] += a[i - 1];
    }
    for (int i = n + 1; i <= 2 * n; i++)
        a[i] += a[i - 1];
    for (int d = 1; d < n; d++)
        for (int l = 1; l + d <= n * 2; l++) {
            int r = l + d;
            dp[0][l][r] = INF;
            dp[1][l][r] = -INF;
            for (int k = l; k < r; k++) {
                //dp[0][l][r] = min(dp[0][l][r], dp[0][l][k] + dp[0][k % n + 1][(r - 1) % n + 1] + a[r] - a[l - 1]);
                //dp[1][l][r] = max(dp[1][l][r], dp[1][l][k] + dp[1][k % n + 1][(r - 1) % n + 1] + a[r] - a[l - 1]);
                dp[0][l][r] = min(dp[0][l][r], dp[0][l][k] + dp[0][k + 1][r] + a[r] - a[l - 1]);
                dp[1][l][r] = max(dp[1][l][r], dp[1][l][k] + dp[1][k + 1][r] + a[r] - a[l - 1]);
            }
        }
    int ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[0][i][i + n - 1]);
    printf("%d\n", ans);
    ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[1][i][i + n - 1]);
    printf("%d\n", ans);
    return 0;
}