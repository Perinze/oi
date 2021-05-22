#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
map<ll, ll> mp;
int n;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        scanf("%d", &n);
        ll ans = 0, x;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x);
            ans += mp[x] * (n + 1 - i);
            mp[x] += i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}