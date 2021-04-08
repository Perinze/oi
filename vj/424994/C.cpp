#include <cstdio>
#include <algorithm>
using namespace std;

int n, t;
int a[30];
int dp[30][1010];

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    // dp[i][j] = the number of combinations of previous i items which rest j
    // dp[i][j] += dp[i][j - k], k in previous i items
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            for (int k = 1; k <= i; k++) {
                if (j - a[k] >= 0)
                    dp[i][j] += dp[i][j - a[k]];
            }
        }
    }
    printf("%d\n", dp[n][t]);
    return 0;
}