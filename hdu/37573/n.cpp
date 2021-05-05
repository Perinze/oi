#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100010;
const ll mod = 1000000007;
int n;
ll seq[maxn];
ll num[maxn];
ll bit[maxn];

void add(int i, ll x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x, bit[i] %= mod;
}

ll sum(int i)
{
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i], s %= mod;
    return s;
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            scanf("%lld", seq + i);
            num[i] = seq[i];
        }
        sort(num + 1, num + 1 + n);
        int cnt = unique(num + 1, num + 1 + n) - num - 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(num + 1, num + 1 + cnt, seq[i]) - num;
            ll x = 1 + sum(pos);
            ans += x, ans %= mod;
            add(pos, x);
        }
        printf("%lld\n", ans);
    }
    return 0;
}