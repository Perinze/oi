#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 100010;
priority_queue<ll, vector<ll>, greater<ll>> q;
ll n, m, x;
ll a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	ll enemy;
	for (ll i = 0; i < n; i++) {
		cin >> enemy;
		a[i] = (enemy - 1) / x + 1;
	}
	for (ll i = 0; i < min(n, m); i++) {
		q.push(a[i]);
	}
	ll cnt = 0;
	for (ll i = min(n, m); i < n; i++) {
		cnt = q.top();
		q.pop();
		q.push(cnt + a[i]);
	}
	ll ans = -1;
	while (!q.empty()) {
		ans = max(ans, q.top());
		q.pop();
	}
	cout << ans << endl;
	return 0;
}