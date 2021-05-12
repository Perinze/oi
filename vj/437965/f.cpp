#include <iostream>
using namespace std;

typedef long long ll;
const ll maxn = 4096 + 10;

ll bit[2][maxn][maxn], n, m;

ll query(ll bit[maxn][maxn], ll i_, ll j_) // query a[i], not prefix sum pre[i]
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i) {
        for (ll j = j_; j > 0; j -= j & -j) {
		    s += bit[i][j];
        }
    }
	return s;
}

void add(ll bit[maxn][maxn], ll i_, ll j_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i) {
        for (ll j = j_; j <= m; j += j & -j) {
		    bit[i][j] += x;
        }
    }
}

ll query(ll i, ll j)
{
    return i * query(bit[0], i, j) - query(bit[1], i, j);
}

ll query(ll li, ll lj, ll ri, ll rj) // query sum of [l, r]
{
    return query(ri, rj) - query(li - 1, rj) - query(ri, lj - 1) + query(li - 1, lj - 1);
}

void add(ll li, ll lj, ll ri, ll rj, ll x) // add x to every element of [l, r]
{
	add(bit[0], l, x), add(bit[0], r + 1, -x);
    add(bit[1], l, (l - 1) * x), add(bit[1], r + 1, r * (-x));
}
