#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
typedef long long ll;

const ll maxn = 1e5 + 5;
ll dat[4 * maxn], lazy[4 * maxn];
ll n;  // size of array, not of the tree
ll arr[maxn];

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
}

void pushup(ll k)
{
    dat[k] = dat[ls] + dat[rs];
}

void pushdown(ll k)
{
    if (k < n - 1) {
        lazy[ls] += lazy[k];
        lazy[rs] += lazy[k];
    }
    lazy[k] = 0;
}

void build(ll a, ll b, ll k, ll l, ll r)
{
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1];
        return;
    }
    build(a, b, ls, l, (l + r) / 2);
    build(a, b, rs, (l + r) / 2, r);
    pushup(k);
}

void update(ll a, ll b, ll x, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        lazy[k] += x;
        return;
    }
    dat[k] += (min(b, r) - max(a, l)) * x;
    update(a, b, x, ls, l, (l + r) / 2);
    update(a, b, x, rs, (l + r) / 2, r);
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (lazy[k]) {
        dat[k] += (r - l) * lazy[k];
        pushdown(k);
    }
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, ls, l, (l + r) / 2);
    ll vr = query(a, b, rs, (l + r) / 2, r);
    return vl + vr;
}

int main()
{
	ios::sync_with_stdio(false);
	ll m, q;
	cin >> m >> q;
	for (ll i = 0; i < m; i++) {
		cin >> arr[i];
	}
	init(m);
	build(0, n, 0, 0, n);
	ll c, l, r, k;
	while (q--) {
		cin >> c;
		if (c == 1) {
			cin >> l >> r >> k;
			update(l - 1, r, k, 0, 0, n);
		} else {
			cin >> l >> r;
			cout << query(l - 1, r, 0, 0, n) << endl;
		}
	}
	return 0;
}