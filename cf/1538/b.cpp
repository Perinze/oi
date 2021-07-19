#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int n;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0;
		bool eq = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && a[i] != a[i - 1]) eq = false;
			sum += a[i];
		}
		if (eq) {
			cout << 0 << endl;
			continue;
		}
		if (sum % n) {
			cout << -1 << endl;
			continue;
		}
		sort(a + 1, a + 1 + n);
		int each = sum / n;
		int ans;
		for (int i = 1; i <= n; i++) {
			if (a[i] > each) {
				ans = i;
				break;
			}
		}
		cout << n - ans + 1 << endl;
	}
}