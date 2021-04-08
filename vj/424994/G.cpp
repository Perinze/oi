#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 1010;
int dp[MAXM];
int a[] = {0, 10, 20, 50, 100};
int M;

int main()
{
    scanf("%d", &M);
    dp[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = a[i]; j <= M; j++)
            dp[j] += dp[j - a[i]];
    printf("%d\n", dp[M]);
    return 0;
}