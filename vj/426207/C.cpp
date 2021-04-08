#include <cstdio>
#include <cstring>
<<<<<<< HEAD
#include <cmath>
#include <algorithm>
using namespace std;

int dp[20][10][10][10][10];
int s[10][10][10][10];
int a[10][10];
int n;
const int INF = 0x3f3f3f3f;
=======
#include <algorithm>
using namespace std;

int n;
int dp[20][10][10][10][10];
int a[10][10];
int s[10][10];

inline int gsum(int i1, int j1, int i2, int j2)
{
    return s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1];
}
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
<<<<<<< HEAD
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
=======
            scanf("%d", &s[i][j]);
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            for (int k = i; k <= 8; k++)
                for (int l = j; l <= 8; l++)
                    dp[0][i][j][k][l] = gsum(i, j, k, l);
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
}