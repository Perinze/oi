#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define MAXN 505
int a[MAXN];
int b[MAXN];
int la, lb;
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
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
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    tmp = a[i];
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        printf("%d\n", dp[la][lb]);
        if (t) putchar('\n');
    }
    return 0;
}