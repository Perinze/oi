#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll maxn = 2e5 + 5;
ll n;
ll a[maxn], b[maxn];
ll x[maxn];

int main()
{
	ios::sync_with_stdio(false);
	ll T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		x[0] = a[0];
		for (ll i = 1; i < n; i++) {
			x[i] = a[i] | x[i - 1];
			b[i] = x[i] ^ a[i];
		}
		for (ll i = 0; i < n; i++)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}