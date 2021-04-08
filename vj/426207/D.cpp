#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int n;
int dp[MAXN];
int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        dp[1] = a[1];
        dp[2] = max(dp[1], a[2]);
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}