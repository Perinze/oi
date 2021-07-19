#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 2e5 + 5;

ll a[maxn];
ll d[maxn];
ll n, q, s, t;
ll sum = 0;

void inc(ll from, ll to)
{
	ll ad = 0;
	ad -= from * (from > 0 ? s : t);
	ad += to * (to > 0 ? s : t);
	sum += ad;
}

/*
void printd()
{
	for (ll i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << endl;
}
*/

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q >> s >> t;
	s = -s;
	t = -t;
	for (ll i = 0; i <= n; i++) {
		cin >> a[i];
		if (i) {
			d[i] = a[i] - a[i - 1];
			sum += d[i] * (d[i] > 0 ? s : t);
		}
	}
	//printd();
	ll l, r, x;
	for (ll i = 0; i < q; i++) {
		cin >> l >> r >> x;
		inc(d[l], d[l] + x);
		if (r + 1 <= n) inc(d[r + 1], d[r + 1] - x);
		cout << sum << endl;
		d[l] += x;
		d[r + 1] -= x;
		//printd();
	}
	return 0;
}