#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
ll n;

int main()
{
    ll T;
    scanf("%lld", &T);
    while (T--) {
        map<ll, ll> group;
        scanf("%lld", &n);
        ll x;
        for (ll i = 1; i <= n; i++) {
            scanf("%lld", &x);
            group[x - i]++;
        }
        ll ans = 0;
        for (auto ite = group.begin(); ite != group.end(); ite++) {
            ans += ite->second * (ite->second - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}