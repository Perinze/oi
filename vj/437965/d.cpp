#include <iostream>
using namespace std;

typedef long long ll;
const ll maxn = 4096 + 10, maxm = 4096 + 10;
ll bit[maxn][maxm], n, m;

ll query(int i_, int j_)
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		for (ll j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

inline ll query(int i1, int j1, int i2, int j2)
{
    return query(i2, j2) - query(i1 - 1, j2) - query(i2, j1 - 1) + query(i1 - 1, j1 - 1);
}

void add(ll i_, int j_, int x)
{
	for (ll i = i_; i <= n; i += i & -i)
		for (ll j = j_; j <= m; j += j & -j)
			bit[i][j] += x;
}

int main()
{
    cin >> n >> m;
    ll cmd;
    while (cin >> cmd) {
        if (cmd == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            add(x, y, k);
        } else {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << query(a, b, c, d) << endl;
        }
    }
    return 0;
}