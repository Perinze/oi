#include <cstdio>
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll x;
        scanf("%lld", &x);
        ll y = x;
        int b = 0;
        while (y) {
            y >>= 1;
            b++;
        }
        b--;
        ll ans = (1 << b) - 1;
        printf("%lld\n", ans);
    }
    return 0;
}