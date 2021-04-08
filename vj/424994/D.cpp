#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 10010, MAXN = 30;
int dp[MAXN][MAXL];
int path[MAXN][MAXL];
int l, n;
int a[MAXN];

void recover(int i, int j)
{
    if (i == 0) return;
    recover(i - 1, path[i][j]);
    if (path[i][j] < j) printf("%d ", a[i]);
}

int main()
{
    while (~scanf("%d%d", &l, &n)) {
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= l; j++) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = j;
                if (j >= a[i]) {
                    int tmp = dp[i - 1][j - a[i]] + a[i];
                    if (tmp > dp[i][j]) {
                        dp[i][j] = tmp;
                        path[i][j] = j - a[i];
                    }
                }
            }
/*
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= l; j++)
                printf("%d\t", dp[i][j]);
            puts("");
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= l; j++)
                printf("%d\t", path[i][j]);
            puts("");
        }
*/
        recover(n, l);
        printf("sum:%d\n", dp[n][l]);
    }
    return 0;
}