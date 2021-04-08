#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[102];
int dp[2][102];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
    }

    for (int i = n; i >= 0; i--) {
        for (int j = n + 1; j > i; j--) {
            if (a[i] > a[j]) dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }

/*
    printf("\tleft\tright\n");
    for (int i = 1; i <= n; i++)
        printf("%d:\t%d\t%d\n", i, dp[0][i], dp[1][i]);
*/

    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    printf("%d\n", n - ans);

    return 0;
}