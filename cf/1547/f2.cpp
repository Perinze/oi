#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 2e5 + 5;
const ll logmaxn = 20;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll a[maxn];
ll st[maxn][logmaxn];
ll n, logn;

void stinit(ll n) {
    for (ll i = 1; i <= n; i++) st[i][0] = a[i];
    for (ll i = 1; i <= logn; i++)
        for (ll j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = gcd(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
}

ll stquery(ll l, ll r) {
    ll k = log2(r - l + 1);
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

bool C(ll l, ll com) {
	for (ll i = 1; i <= n; i++) {
		ll r = i + l - 1;
		ll res = stquery(i, min(n, r));
		if (r > n) res = gcd(res, stquery(1, r % n));
		if (res != com) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		logn = log2(n);
		for (ll i = 1; i <= n; i++)
			cin >> a[i];
		stinit(n);
		ll com = stquery(1, n);
		ll lb = 0, ub = n + 1;
		while (lb + 1 < ub) {
			ll md = (lb + ub) >> 1;
			if (C(md, com)) {
				ub = md;
			} else {
				lb = md;
			}
		}
		cout << lb << endl;
	}
	return 0;
}