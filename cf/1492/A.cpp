#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ll p, a, b, c;
        scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
        ll ans = 1000000000000000001;
        ll zero = 0;
        if (p % a) ans = min(ans, ((p / a) + 1) * a - p);
        else ans = min(ans, zero);
        if (p % b) ans = min(ans, ((p / b) + 1) * b - p);
        else ans = min(ans, zero);
        if (p % c) ans = min(ans, ((p / c) + 1) * c - p);
        else ans = min(ans, zero);
        printf("%lld\n", ans);
    }
    return 0;
}