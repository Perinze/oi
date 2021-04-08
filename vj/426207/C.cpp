#include <cstdio>
#include <cstring>
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

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            for (int k = i; k <= 8; k++)
                for (int l = j; l <= 8; l++)
                    dp[0][i][j][k][l] = gsum(i, j, k, l);
}