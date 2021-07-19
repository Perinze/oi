#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	if (a == b) {
		cout << min(x, y) / a << endl;
		return;
	}
	if (a < b) {
		swap(a, b);
	}
	ll l = 0, r = 1e9 + 10;
	ll ans;
	ll m;
	while (r - l > 1) {
		m = (l + r) / 2;
		ll hi = floorl((x - m * b) * 1.0l / (a - b));
		ll lo = ceill((y - m * a) * 1.0l / (b - a));
		if (max(lo, 0ll) <= min(hi, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}