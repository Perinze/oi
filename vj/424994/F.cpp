#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 40, MAXM = 510;
int dp[MAXN][MAXM];
int a[MAXN];
int N, M;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++)
            scanf("%d", a + i);

        sort(a + 1, a + 1 + N);
        int n = -1, m = M;
        for (int i = 1; i <= N; i++) {
            if (m >= a[i]) m -= a[i];
            else {
                n = i - 1;
                break;
            }
        }
        if (n == -1) n = N;

        for (int i = 0; i <= M; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= N; i++)
            for (int j = M; j >= a[i]; j--)
                for (int k = n; k > 0; k--)
                    dp[k][j] += dp[k - 1][j - a[i]];
        if (n) printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", dp[n][M], n);
        else puts("Sorry, you can't buy anything.");
    }
    return 0;
}