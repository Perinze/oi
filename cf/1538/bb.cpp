#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int pre[maxn];
int n;

int C(int p)
{
	int sum = pre[n] - pre[p - 1] - a[p - 1] * (n - p + 1);
	int need = a[p - 1] * (p - 1) - pre[p - 1];
	return sum - need;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		bool eq = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && a[i] != a[i - 1]) eq = false;
		}
		if (eq) {
			cout << 0 << endl;
			continue;
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + a[i];
		}
		/*
		int ans = -1;
		for (int i = n; i >= 1; i--) {
			if (C(i) == 0) ans = i;
			break;
		}
		*/
		int l = 1, r = n;
		int ans = -1;
		int mid;
		while (l < r) {
			int mid = (l + r) / 2;
			int res = C(mid);
			if (res == 0) {
				ans = mid;
				break;
			} else if (res > 0) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (ans == -1) cout << -1 << endl;
		else cout << n - ans + 1 << endl;
	}
}