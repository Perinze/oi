#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll maxn = 3e5 + 5;
ll a[maxn], t[maxn];
ll ans[maxn];
ll n, k;
pll ls[maxn];

int main()
{
	ios::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--) {
		memset(ans, 0x3f, sizeof(ans));
		cin >> n >> k;
		for (ll i = 0; i < k; i++)
			cin >> a[i];
		for (ll i = 0; i < k; i++)
			cin >> t[i];

		for (ll i = 0; i < k; i++) {
			ls[i] = pll(a[i] + t[i], a[i]);
		}
		sort(ls, ls + k);
		/*
		for (ll i = 0; i < k; i++) {
			cout << "(" << ls[i].first << ", " << ls[i].second << ") ";
		}
		cout << endl;
		*/
		ll j = 0;
		bool quit = false;
		for (ll i = 1; i <= n; i++) {
			while (i > ls[j].second) {
				j++;
				if (j >= k) {
					quit = true;
					break;
				}
			}
			if (quit) break;
			//cout << i << ": " << j << ", ";
			ll x = ls[j].first - i;
			ans[i] = min(ans[i], x);
		}
		//cout << endl;

		for (ll i = 0; i < k; i++)
			ls[i] = pll(a[i] - t[i], a[i]);
		sort(ls, ls + k, greater<pll>());
		/*
		for (ll i = 0; i < k; i++) {
			cout << "(" << ls[i].first << ", " << ls[i].second << ") ";
		}
		cout << endl;
		*/
		j = 0;
		quit = false;
		for (ll i = n; i > 0; i--) {
			while (i < ls[j].second) {
				j++;
				if (j >= k) {
					quit = true;
					break;
				}
			}
			if (quit) break;
			//cout << i << ": " << j << ", ";
			ll x = i - ls[j].first;
			ans[i] = min(ans[i], x);
		}
		//cout << endl;

		for (ll i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}