#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[20][10][10][10][10];
int s[10][10][10][10];
int a[10][10];
int n;
const int INF = 0x3f3f3f3f;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    memset(dp, INF, sizeof(dp));

    for (int y1 = 1; y1 <= 8; y1++)
        for (int x1 = 1; x1 <= 8; x1++)
            for (int y2 = y1; y2 <= 8; y2++)
                for (int x2 = x1; x2 <= 8; x2++) {
                    int sum = a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1];
                    dp[0][y1][x1][y2][x2] = s[y1][x1][y2][x2] = sum * sum;
                }

    //printf("%d\n", s[6][7][8][8]);
    for (int k = 1; k < n; k++)
        for (int y1 = 1; y1 <= 8; y1++)
            for (int x1 = 1; x1 <= 8; x1++)
                for (int y2 = y1; y2 <= 8; y2++)
                    for (int x2 = x1; x2 <= 8; x2++) {
                        int &d = dp[k][y1][x1][y2][x2];
                        for (int i = y1; i < y2; i++) {
                            d = min(d, dp[k - 1][y1][x1][i][x2] + s[i + 1][x1][y2][x2]);
                            d = min(d, s[y1][x1][i][x2] + dp[k - 1][i + 1][x1][y2][x2]);
                        }
                        for (int i = x1; i < x2; i++) {
                            d = min(d, dp[k - 1][y1][x1][y2][i] + s[y1][i + 1][y2][x2]);
                            d = min(d, s[y1][x1][y2][i] + dp[k - 1][y1][i + 1][y2][x2]);
                        }
                    }
    double avg = (double)a[8][8] / n;
    double res = dp[n - 1][1][1][8][8];
    //printf("%f %f\n", avg, res);
    double ans = sqrt((double)res / (double)n - (double)avg * avg);
    printf("%.3f\n", ans);
    return 0;
}