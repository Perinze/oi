#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
#define MAXN 510
int n, m;
int a[MAXN], b[MAXN];
=======
#define MAXN 505
int a[MAXN];
int b[MAXN];
int la, lb;
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
<<<<<<< HEAD
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
=======
        memset(dp, 0, sizeof(dp));
        scanf("%d", &la);
        for (int i = 1; i <= la; i++)
            scanf("%d", a + i);
        scanf("%d", &lb);
        for (int i = 1; i <= lb; i++)
            scanf("%d", b + i);
        
        int tmp = INT_MIN;
        for (int i = 1; i <= la; i++)
            for (int j = 1; j <= lb; j++)
                if (a[i] == b[j] && a[i] >= tmp) {
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    tmp = a[i];
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
<<<<<<< HEAD
            }
        printf("%d\n", dp[n][m]);
        if (t)
            printf("\n");
=======
        printf("%d\n", dp[la][lb]);
        if (t) putchar('\n');
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
    }
    return 0;
}