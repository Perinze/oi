#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MAXN = 100010;
ll dat[4 * MAXN], lazy[4 * MAXN];
ll n;  // size of array, not of the tree

char gch()
{
    char c;
    while ((c = getchar()) != EOF) {
        if (c == 'Q' || c == 'C')
            return c;
    }
}

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
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
    ll *array = dat + n - 1;
    for (ll i = 0; i < m; i++) {
        scanf("%lld", array + i);
    }
    for (ll i = n - 2; i >= 0; i--)
        dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
    while (q--) {
        /*
        int ret = 0;
        for (ll i = 0; i < 2 * n - 1; i++) {
            cout << dat[i] << ' ';
            if (i == ret) {
                cout << endl;
                ret = (ret + 1) * 2;
            }
        }
        cout << endl;
        ret = 0;
        for (ll i = 0; i < 2 * n - 1; i++) {
            cout << lazy[i] << ' ';
            if (i == ret) {
                cout << endl;
                ret = (ret + 1) * 2;
            }
        }
        cout << endl;
        */
        char c;
        ll l, r;
        c = gch();
        scanf("%lld%lld", &l, &r);
        l--;
        if (c == 'Q')
            printf("%lld\n", query(l, r, 0, 0, n));
        else {
            ll a;
            scanf("%lld", &a);
            update(l, r, a, 0, 0, n);
        }
    }
    return 0;
}