#include <iostream>
using namespace std;

typedef long long ll;
const ll maxn = 4096 + 10;
const ll maxm = maxn;

ll bit[4][maxn][maxm], n, m;

ll query(ll bit[maxn][maxm], ll i_, ll j_)
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		for (ll j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

void add(ll bit[maxn][maxm], ll i_, ll j_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i)
		for (ll j = j_; j <= m; j += j & -j)
			bit[i][j] += x;
}

void add(ll i1, ll j1, ll i2, ll j2, ll x)
{
	add(bit[0], i1, j1, x);
	add(bit[0], i1, j2 + 1, -x);
	add(bit[0], i2 + 1, j1, -x);
	add(bit[0], i2 + 1, j2 + 1, x);

	add(bit[1], i1, j1, x * (i1 - 1));
	add(bit[1], i1, j2 + 1, -x * (i1 - 1));
	add(bit[1], i2 + 1, j1, -x * i2);
	add(bit[1], i2 + 1, j2 + 1, x * i2);

	add(bit[2], i1, j1, x * (j1 - 1));
	add(bit[2], i1, j2 + 1, -x * j2);
	add(bit[2], i2 + 1, j1, -x * (j1 - 1));
	add(bit[2], i2 + 1, j2 + 1, x * j2);

	add(bit[3], i1, j1, x * (i1 - 1) * (j1 - 1));
	add(bit[3], i1, j2 + 1, -x * (i1 - 1) * j2);
	add(bit[3], i2 + 1, j1, -x * i2 * (j1 - 1));
	add(bit[3], i2 + 1, j2 + 1, x * i2 * j2);
}

ll query(ll i, ll j)
{
	return i * j * query(bit[0], i, j)
	         - j * query(bit[1], i, j)
			 - i * query(bit[2], i, j)
			     + query(bit[3], i, j);
}

ll query(ll i1, ll j1, ll i2, ll j2)
{
	return query(i2, j2) - query(i1 - 1, j2) - query(i2, j1 - 1) + query(i1 - 1, j1 - 1);
}

int main()
{
    cin >> n >> m;
    ll cmd;
    ll a, b, c, d, e;
    while (cin >> cmd) {
        if (cmd == 1) {
            cin >> a >> b >> c >> d >> e;
            add(a, b, c, d, e);
        } else {
            cin >> a >> b >> c >> d;
            cout << query(a, b, c, d) << endl;
        }
    }
    return 0;
}