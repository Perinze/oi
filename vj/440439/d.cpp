#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll maxn = 1e5 + 10;
ll dat[maxn * 4], lazy[maxn * 4];
ll arr[maxn];
ll n;

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
}

void build(ll a, ll b, ll k, ll l, ll r)
{
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1];
        return;
    }
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
    dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
}

void update(ll a, ll b, ll x, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        lazy[k] += x;
        return;
    }
    dat[k] += (min(b, r) - max(a, l)) * x;
    update(a, b, x, k * 2 + 1, l, (l + r) / 2);
    update(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (lazy[k]) {
        dat[k] += (r - l) * lazy[k];
        if (k < n - 1) {
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        lazy[k] = 0;
    }
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
}

int main()
{
    ll m, q;
    scanf("%lld%lld", &m, &q);
    init(m);
    for (ll i = 0; i < m; i++)
        scanf("%lld", arr + i);
    build(0, n, 0, 0, n);
    char tmp[2];
    ll a, b, c;
    while (q--) {
        scanf("%s", tmp);
        if (tmp[0] == 'Q') {
            scanf("%lld%lld", &a, &b);
            printf("%lld\n", query(a - 1, b, 0, 0, n));
        } else {
            scanf("%lld%lld%lld", &a, &b, &c);
            update(a - 1, b, c, 0, 0, n);
        }
    }
    return 0;
}