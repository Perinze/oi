#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
typedef long long ll;
const int maxn = 1e5 + 10;

ll dat[maxn * 4], lazyadd[maxn * 4], lazymul[maxn * 4];
ll arr[maxn];
ll n, P;

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
    for (int i = 0; i < n * 2 - 1; i++)
        lazymul[i] = 1;
}

void pushup(ll k)
{
    dat[k] = (dat[ls] + dat[rs]) % P;
}

void build(ll k, ll l, ll r)
{
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1] % P;
        return;
    }
    build(ls, l, (l + r) / 2);
    build(rs, (l + r) / 2, r);
    pushup(k);
}

void add(ll x, ll k)
{
    lazyadd[k] = (lazyadd[k] + x) % P;
}

void mul(ll x, ll k)
{
    lazymul[k] = (lazymul[k] * x) % P;
    lazyadd[k] = (lazyadd[k] * x) % P;
}

void pushdown(ll k, ll l, ll r)
{
    if (lazymul[k] != 1) {
        //if (k < n - 1) {
            mul(lazymul[k], ls);
            mul(lazymul[k], rs);
        //}
        dat[k] = (dat[k] * lazymul[k]) % P;
        lazymul[k] = 1;
    }
    if (lazyadd[k] != 0) {
        //if (k < n - 1) {
            add(lazyadd[k], ls);
            add(lazyadd[k], rs);
        //}
        dat[k] = (dat[k] + (r - l) * lazyadd[k] % P) % P;
        lazyadd[k] = 0;
    }
}

void update(ll a, ll b, ll x, ll t, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        if (t == 1) // mul
            mul(x, k);
        else
            add(x, k);
        pushdown(k, l, r);
        return;
    }
    pushdown(k, l, r);
    update(a, b, x, t, ls, l, (l + r) / 2);
    update(a, b, x, t, rs, (l + r) / 2, r);
    dat[k] = (dat[ls] + dat[rs]) % P;
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (lazymul[k] != 1 || lazyadd[k] != 0) {
        pushdown(k, l, r);
    }
    if (a <= l && r <= b) return dat[k] % P;
    ll vl = query(a, b, ls, l, (l + r) / 2);
    ll vr = query(a, b, rs, (l + r) / 2, r);
    return (vl + vr) % P;
}

void print()
{
    printf("dat:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", dat[i]);
    puts("");
    printf("lazymul:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", lazymul[i]);
    puts("");
    printf("lazyadd:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", lazyadd[i]);
    puts("");
}

int main()
{
    ll m;
    scanf("%lld%lld", &m, &P);
    init(m);
    for (int i = 0; i < m; i++)
        scanf("%lld", arr + i);
    build(0, 0, n);
    print();
    ll q;
    scanf("%lld", &q);
    ll c, l, r, x;
    while (q--) {
        scanf("%lld%lld%lld", &c, &l, &r);
        if (c != 3) {
            scanf("%lld", &x);
            update(l - 1, r, x, c, 0, 0, n);
        } else {
            printf("%lld\n", query(l - 1, r, 0, 0, n));
        }
        print();
    }
    return 0;
}