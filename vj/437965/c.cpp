#include <iostream>
using namespace std;

typedef long long ll;
const ll maxn = 1e6 + 10;
ll bit[2][maxn];
ll n;

ll query(ll *bit, ll i_) // query a[i], not prefix sum pre[i]
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

void add(ll *bit, ll i_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

ll query(ll i)
{
    return i * query(bit[0], i) - query(bit[1], i);
}

ll query(ll l, ll r)
{
    return query(r) - query(l - 1);
}

void add(ll l, ll r, ll x) // add x to every element of [l, r]
{
	add(bit[0], l, x), add(bit[0], r + 1, -x);
    add(bit[1], l, (l - 1) * x), add(bit[1], r + 1, r * (-x));
}

int main()
{
    ll q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        add(i, i, x);
    }
    ll cmd;
    for (ll i = 1; i <= q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            add(l, r, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }
    return 0;
}