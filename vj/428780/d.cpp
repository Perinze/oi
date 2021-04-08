#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 200010
#define maxs LLONG_MAX
typedef long long ll;

ll n, m; ll S;
ll w[maxn], v[maxn];
ll l[maxn], r[maxn];
ll z[maxn];

ll cnts[maxn];
ll vs[maxn];
ll C(ll x)
{
    ll res = 0;
    memset(cnts, 0, sizeof(cnts));
    memset(vs, 0, sizeof(vs));
    for (ll i = 1; i <= n; i++) {
        if (w[i] >= x) {
            cnts[i] = cnts[i - 1] + 1;
            vs[i] = vs[i - 1] + v[i];
        } else {
            cnts[i] = cnts[i - 1];
            vs[i] = vs[i - 1];
        }
    }
    for (ll i = 1; i <= m; i++) {
        res += (cnts[r[i]] - cnts[l[i] - 1]) * (vs[r[i]] - vs[l[i] - 1]);
    }
    return res;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &S);
    for (ll i = 1; i <= n; i++) 
        scanf("%lld%lld", w + i, v + i);
    for (ll i = 1; i <= m; i++)
        scanf("%lld%lld", l + i, r + i);
    ll lo = 0, hi = maxs;
    ll ans = maxs;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll res = C(mid);
        if (res > S) {
            lo = mid + 1;
            ans = min(ans, res - S);
        } else if (res < S) {
            hi = mid;
            ans = min(ans, S - res);
        } else {
            ans = min(ans, res > S ? res - S : S - res);
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}