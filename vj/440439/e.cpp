#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
#define mid ((l + r) / 2)
typedef long long ll;
const int maxn = 1e5 + 10;

ll dat[maxn * 4], add[maxn * 4], mul[maxn * 4];
ll arr[maxn];
ll n, P;

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
}

void pushup(ll k)
{
    dat[k] = (dat[ls] + dat[rs]) % P;
}

void build(ll k, ll l, ll r)
{
    mul[k] = 1;
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1] % P;
        return;
    }
    build(ls, l, mid);
    build(rs, mid, r);
    pushup(k);
}

void eval(ll k, ll mulx, ll addx, ll l, ll r)
{
    dat[k] = (dat[k] * mulx + (r - l) * addx) % P;
    mul[k] = mul[k] * mulx % P;
    add[k] = (add[k] * mulx + addx) % P;
}

void pushdown(ll k, ll l, ll r)
{
    eval(ls, mul[k], add[k], l, mid);
    eval(rs, mul[k], add[k], mid, r);
    add[k] = 0, mul[k] = 1;
}

void update(ll a, ll b, ll mulx, ll addx, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        eval(k, mulx, addx, l, r);
        return;
    }
    pushdown(k, l, r);
    update(a, b, mulx, addx, ls, l, mid);
    update(a, b, mulx, addx, rs, mid, r);
    pushup(k);
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k] % P;
    pushdown(k, l, r);
    ll vl = query(a, b, ls, l, mid);
    ll vr = query(a, b, rs, mid, r);
    return (vl + vr) % P;
}

void print()
{
    printf("dat:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", dat[i]);
    puts("");
    printf("mul:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", mul[i]);
    puts("");
    printf("add:");
    for (int i = 0; i < n * 2 - 1; i++) printf(" %d", add[i]);
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
    ll t, l, r, x;
    while (q--) {
        scanf("%lld%lld%lld", &t, &l, &r);
        if (t != 3)
            scanf("%lld", &x);
        if (t == 1)
            update(l, r, x, 0, 0, 0, n);
        else if (t == 2)
            update(l, r, 1, x, 0, 0, n);
        else
            printf("%lld\n", query(l - 1, r, 0, 0, n));
        print();
    }
    return 0;
}