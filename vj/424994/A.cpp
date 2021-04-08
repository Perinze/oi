#include <cstdio>
#include <algorithm>

const int MAXN = 11;
int dp[MAXN][MAXN][MAXN][MAXN];
int map[MAXN][MAXN];
int n;

int main()
{
    scanf("%d", &n);
    int x, y, w;
    for (;;) {
        scanf("%d", &x);
        if (x == 0) break;
        scanf("%d%d", &y, &w);
        map[y][x] = w;
    }
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++)
                for (int d = 1; d <= n; d++) {
                    dp[a][b][c][d] = dp[a - 1][b][c - 1][d];
                    dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a - 1][b][c][d - 1]);
                    dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b - 1][c - 1][d]);
                    dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b - 1][c][d - 1]);
                    dp[a][b][c][d] += map[a][b];
                    if (a != c || b != d)
                        dp[a][b][c][d] += map[c][d];
                }
    printf("%d\n", dp[n][n][n][n]);
    return 0;
}