<<<<<<< HEAD
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 40;
int dp[MAXN][MAXN];
int root[MAXN][MAXN];
int n;
int a[MAXN];

void dfs(int l, int r)
{
    if (l > r) return;
    if (l == r) {
        printf("%d ", l);
        return;
    }
    int v = root[l][r];
    printf("%d ", v);
    dfs(l, v - 1);
    dfs(v + 1, r);
}

int main()
{
    memset(root, -1, sizeof(root));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        dp[i][i] = a[i];
        dp[i][i - 1] = 1;
        //printf("dp[%d][%d]=%d\n", i, i, dp[i][i]);
    }
    for (int d = 1; d < n; d++)
        for (int l = 1; l + d <= n; l++) {
            int r = l + d;
            /*
            //dp[l][r] = max(dp[l][r - 1] + a[r], dp[l + 1][r] + a[l]);
            if (dp[l][r - 1] + a[r] > dp[l][r]) {
                dp[l][r] = dp[l][r - 1] + a[r];
                //printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
                root[l][r] = r;
                //printf("root[%d][%d]=%d\n", l, r, root[l][r]);
            }
            if (dp[l + 1][r] + a[l] > dp[l][r]) {
                dp[l][r] = dp[l + 1][r] + a[l];
                //printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
                root[l][r] = l;
                //printf("root[%d][%d]=%d\n", l, r, root[l][r]);
            }
            */
            for (int k = l; k <= r; k++) {
                //dp[l][r] = max(dp[l][r], dp[l][k - 1] * dp[k + 1][r] + a[k]);
                if (dp[l][k - 1] * dp[k + 1][r] + a[k] > dp[l][r]) {
                    dp[l][r] = dp[l][k - 1] * dp[k + 1][r] + a[k];
                    //printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
                    root[l][r] = k;
                    //printf("root[%d][%d]=%d\n", l, r, root[l][r]);
                }
            }
        }
    printf("%d\n", dp[1][n]);
    dfs(1, n);
    printf("\n");
    return 0;
    return 0;
=======
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 40;
int dp[MAXN][MAXN];
int root[MAXN][MAXN];
int n;
int a[MAXN];

void dfs(int l, int r)
{
    int v = root[l][r];
    printf("%d", v);
    if (l == r) return;
    dfs(l, v - 1);
    dfs(v + 1, r);
}

int main()
{
    memset(root, -1, sizeof(root));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        dp[i][i] = a[i];
        printf("dp[%d][%d]=%d\n", i, i, dp[i][i]);
    }
    for (int d = 1; d < n; d++)
        for (int l = 1; l + d <= n; l++) {
            int r = l + d;
            if (r = l + 1) {
                
            } else {
                for (int k = l + 1; k < r; k++) {
                    //dp[l][r] = max(dp[l][r], dp[l][k - 1] * dp[k + 1][r] + a[k]);
                    if (dp[l][r] == -1 || dp[l][k - 1] * dp[k + 1][r] + a[k] > dp[l][r]) {
                        dp[l][r] = dp[l][k - 1] * dp[k + 1][r] + a[k];
                        printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
                        root[l][r] = k;
                        printf("root[%d][%d]=%d\n", l, r, root[l][r]);
                    }
                }
            }
        }
    printf("%d\n", dp[1][n]);
    dfs(1, n);
    return 0;
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
}