#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2500

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main()
{
    while (~scanf("%s%s", a + 1, b + 1)) {
        int la = strlen(a + 1), lb = strlen(b + 1);
        for (int i = 1; i <= la; i++)
            for (int j = 1; j <= lb; j++) {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        printf("%d\n", dp[la][lb]);
    }
    return 0;
}