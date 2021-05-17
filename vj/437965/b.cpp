#include <iostream>
using namespace std;

typedef long long ll;
const ll maxn = 1e6 + 10;
ll bit[maxn], n; // bit stores d[i] = a[i] - a[i - 1]

ll query(ll i_) // query a[i], not prefix sum pre[i]
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

void add(ll i_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

void add(ll l, ll r, ll x) // add x to every element of [l, r]
{
	add(l, x), add(r + 1, -x);
}

int main()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        add(i, i, x);
    }
    for (ll i = 0; i < q; i++) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            add(l, r, x);
        } else {
            ll i;
            cin >> i;
            cout << query(i) << endl;
        }
    }
    return 0;
}