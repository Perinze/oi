/*
114514
<<< 4 1 5 4 1 1 <<<
0 - f[5][0] 4 - f[4][6] 5 - f[3][5] 0 - f[2][0] 4 - f[1][6] 5 - f[0][5]
1 - f[5][9]             6 - f[3][4] 1 - f[2][9]
2 - f[5][8]             7 - f[3][3] 2 - f[2][8]
3 - f[5][7]             8 - f[3][2] 3 - f[2][7]
                        9 - f[3][1]
4           5           0           4           5
added all dp on digit except a[i]
when each digit select a[i], need to consider the last element
*/
	
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[20][10];

void init()
{
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 18; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i][(j + k) % 10] += dp[i - 1][j];
            }
        }
    }
}

ll cnt(ll x)
{
    if (x < 0) return 0;
    static int a[20];
    int len = 0;
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
    ll res = 0;
    ll tmp = 0;
    for (int i = len; i > 1; i--) {
        for (int j = 0; j < a[i]; j++)
            res += dp[i - 1][(10 - (j + tmp) % 10) % 10];
        tmp = (tmp + a[i]) % 10;
    }
    for (int i = 0; i <= a[1]; i++) {
        if ((tmp + i) % 10 == 0) {
            res++;
            break;
        }
    }
    return res;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        printf("Case #%d: %lld\n", kase++, cnt(r) - cnt(l - 1));
    }
    return 0;
}