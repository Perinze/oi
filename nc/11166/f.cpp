#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxl = 20;

ll p10[maxl];
ll dp[maxl][10];

void init()
{
	ll pd = 1;
	for (ll i = 0; i <= 18; i++) {
		p10[i] = pd;
		pd *= 10;
	}

	ll s = 0;
	for (ll i = 0; i <= 9; i++) {
		if (i % 3 == 0) s++;
		dp[1][i] = s;
	}
	for (ll i = 2; i <= 18; i++) {
		for (ll j = 0; j <= 9; j++) {
			dp[i][j] = dp[i - 1][j] + 3 * (j + 1) * p10[i - 2];
		}
	}
}

ll sum(ll x)
{
	if (x == -1) return 0;
	if (x == 0) return 1;
	vector<ll> vec;
	while (x) {
		vec.push_back(x % 10);
		x /= 10;
	}
	ll ans = 0;
	for (int i = vec.size() - 1; i >= 0; i--) {
		ans += dp[i + 1][vec[i] - 1];
	}
	return ans;
}

ll solve(ll x)
{
	if (x == -1) return 0;
	if (x == 0) return 1;
	ll ans = 0;
	while (x) {
		ans += sum(x);
		x /= 10;
	}
	return ans;
}

int main()
{
	init();
	ll T;
	cin >> T;
	ll l, r;
	while (T--) {
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}