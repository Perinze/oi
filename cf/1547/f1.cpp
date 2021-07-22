#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 2e5 + 5;
const ll maxa = 2e6 + 5;
const ll maxp = 10;
vector<ll> prime;
ll sieve[maxa];
ll n, a[maxn];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void init() {
	sieve[0] = sieve[1] = 1;
	for (ll i = 2; i < maxa; i++) {
		if (!sieve[i]) {
			sieve[i] = i;
			prime.push_back(i);
			for (ll j = i << 1; j < maxa; j += i) {
				sieve[j] = sieve[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	init();
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll T;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 1) T = gcd(a[0], a[1]);
			else if (i > 1) T = gcd(T, a[i]);
		}
		vector<set<ll>> fact(n);
		for (ll i = 0; i < n; i++) {
			a[i] /= T;
			ll x = a[i];
			while (x > 1) {
				fact[i].insert(sieve[x]);
				x /= sieve[x];
			}
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			for (ll p : fact[i]) {
				ll cnt = 1;
				ll l = (i - 1 + n) % n, r = (i + 1) % n;
				while (fact[l].count(p)) {
					fact[l].erase(p);
					cnt++;
					l = (l - 1 + n) % n;
				}
				while (fact[r].count(p)) {
					fact[r].erase(p);
					cnt++;
					r = (r + 1) % n;
				}
				ans = max(ans, cnt);
			}
			fact[i].clear();
		}
		cout << ans << endl;
	}
	return 0;
}