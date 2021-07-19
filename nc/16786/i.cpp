#include <bits/stdc++.h>
using namespace std;

#define mul_rel(a, b) (a == 0 || b == 0 || a % b == 0 || b % a == 0)
using ll = long long;
const ll maxlen = 20;
ll dp[maxlen][10];

void init()
{
	dp[0][0] = 1;
	for (ll len = 1; len < maxlen; len++) {
		for (ll i = 0; i <= 9; i++) {
			for (ll j = 0; j <= 9; j++) {
				if (mul_rel(i, j)) {
					dp[len][i] += dp[len - 1][j];
				}
			}
		}
	}
}

ll dfs(vector<ll> &vec, ll p, ll j)
{
	if (p < 0) return 1;
	ll res = 0;
	ll x = vec[p];
	for (ll i = 0; i < x; i++) {
		if (mul_rel(i, j)) res += dp[p + 1][i];
	}
	if (mul_rel(x, j)) res += dfs(vec, p - 1, x);
	return res;
}

ll sum(ll x)
{
	if (x == 0) return 1;
	if (x == -1) return 0;
	vector<ll> vec;
	while (x) {
		vec.push_back(x % 10);
		x /= 10;
	}
	return dfs(vec, vec.size() - 1, 0);
}

int main()
{
	init();
	for (ll bit = 1; bit <= 3; bit++) {
		for (ll digit = 1; digit <= 9; digit++) {
			printf("dp[%lld][%lld] = %lld\n", bit, digit, dp[bit][digit]);
		}
	}
	ll t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << sum(r) - sum(l - 1) << endl;
	}
	return 0;
}