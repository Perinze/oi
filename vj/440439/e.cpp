#include <bits/stdc++.h>
using namespace std;

#define ls (v * 2 + 1)
#define rs (v * 2 + 2)
#define mid ((l + r) / 2)
typedef long long ll;
const int maxn = 1e5 + 10;

ll dat[maxn * 4], lazymul[maxn * 4], lazyadd[maxn * 4];
ll arr[maxn];
ll n, p;

void print()
{
    cout << "dat:";
    for (int i = 0; i < n * 2 - 1; i++) cout << ' ' << dat[i];
    cout << endl;
    cout << "mul:";
    for (int i = 0; i < n * 2 - 1; i++) cout << ' ' << lazymul[i];
    cout << endl;
    cout << "add:";
    for (int i = 0; i < n * 2 - 1; i++) cout << ' ' << lazyadd[i];
    cout << endl << endl;
}

inline void init(ll m)
{
    n = 1;
    while (n < m) n *= 2; 
}

inline void pullup(ll v)
{
    dat[v] = (dat[ls] + dat[rs]) % p;
    cout << "pullup(" << v << ")" << endl;
    print();
}

void build(ll v)
{
    lazymul[v] = 1;
    if (v >= n - 1) {
        dat[v] = arr[v - n + 1];
    } else {
        build(ls), build(rs);
        pullup(v);
    }
    cout << "build(" << v << ")" << endl;
    print();
}

inline void mul(ll x, ll v, ll l, ll r)
{
    lazymul[v] = (lazymul[v] * x) % p;
    lazyadd[v] = (lazyadd[v] * x) % p;
    dat[v] = (dat[v] * x) % p;
    cout << "mul(" << x << "," << v << "," << l << "," << r << ")" << endl;
    print();
}

inline void add(ll x, ll v, ll l, ll r)
{
    lazyadd[v] = (lazyadd[v] + x % p) % p;
    dat[v] = (dat[v] + (r - l) * v % p) % p;
    cout << "add(" << x << "," << v << "," << l << "," << r << ")" << endl;
    print();
}

void pushdown(ll v, ll l, ll r)
{
    cout << "into pushdown(" << v << "," << l << "," << r << ")" << endl;
    if (lazymul[v] != 1) {
        mul(lazymul[v], ls, l, mid);
        mul(lazymul[v], rs, mid, r);
        lazymul[v] = 1;
    }
    if (lazyadd[v] != 0) {
        add(lazyadd[v], ls, l, mid);
        add(lazyadd[v], rs, mid, r);
        lazyadd[v] = 0;
    }
    cout << "exit pushdown(" << v << "," << l << "," << r << ")" << endl;
    print();
}

void modify(ll a, ll b, ll x, ll tag, ll v, ll l, ll r)
{
    cout << "into modify(" << a << "," << b << "," << x << "," << tag << "," << v << "," << l << "," << r << ")" << endl;
    if (r <= a || b <= l) {
        cout << "exit with nothing done" << endl;
        return;
    }
    if (a <= l && r <= b) {
        if (tag == 1) { //mul
            mul(x, v, l, r);
        } else {
            add(x, v, l, r);
        }
        cout << "exit modify(" << a << "," << b << "," << x << "," << tag << "," << v << "," << l << "," << r << ")" << endl;
        print();
        return;
    }
    pushdown(v, l, r);
    modify(a, b, x, tag, ls, l, mid);
    modify(a, b, x, tag, rs, mid, r);
    pullup(v);
    cout << "exit modify(" << a << "," << b << "," << x << "," << tag << "," << v << "," << l << "," << r << ")" << endl;
    print();
}

ll query(ll a, ll b, ll v, ll l, ll r)
{
    cout << "into query(" << a << "," << b << "," << v << "," << l << "," << r << ")" << endl;
    if (r <= a || b <= l) {
        cout << "exit with 0 returned" << endl;
        return 0;
    }
    if (a <= l && r <= b) {
        cout << "exit return " << dat[v] << endl;
        return dat[v];
    }
    pushdown(v, l, r);
    ll vl = query(a, b, ls, l, mid);
    ll vr = query(a, b, rs, mid, r);
    cout << "exit query(" << a << "," << b << "," << v << "," << l << "," << r << ")" << endl;
    cout << "return " << (vl + vr) % p << endl;
    print();
    return (vl + vr) % p;
}

int main()
{
    ios::sync_with_stdio(false);
    ll m;
    cin >> m >> p;
    for (int i = 0; i < m; i++) cin >> arr[i];
    init(m);
    build(0);
    cin >> m;
    while (m--) {
        ll op, a, b, x;
        cin >> op >> a >> b;
        if (op == 1 || op == 2) {
            cin >> x;
            modify(a - 1, b, x, op, 0, 0, n);
        } else {
            cout << query(a - 1, b, 0, 0, n) << endl;
        }
    }
    return 0;
}