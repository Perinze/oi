#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 4096 + 10;

ll bit[maxn][maxn], n, m;

ll query(ll i_, ll j_)
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		for (ll j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

void add(ll i_, ll j_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i)
		for (ll j = j_; j <= m; j += j & -j)
			bit[i][j] += x;
}

void add(ll i1, ll j1, ll i2, ll j2, ll x)
{
    add(i1, j1, x);
    add(i1, j2 + 1, -x);
    add(i2 + 1, j1, -x);
    add(i2 + 1, j2 + 1, x);
}

int main()
{
    cin >> n >> m;
    int cmd;
    ll a, b, c, d, e;
    while (cin >> cmd) {
        if (cmd == 1) {
            cin >> a >> b >> c >> d >> e;
            add(a, b, c, d, e);
        } else {
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }
    return 0;
}