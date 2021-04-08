#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110, MAXL = 1010;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXL];
int N, M, l;
int t[MAXN], v[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
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
    }
    return 0;
}