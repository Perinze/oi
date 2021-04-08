#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define MAXN 510
int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", b + i);
        int tmp = INT_MIN;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j] && a[i] > tmp) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    tmp = a[i];
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        printf("%d\n", dp[n][m]);
        if (t)
            printf("\n");
    }
    return 0;
}