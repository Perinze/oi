#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n;
int a[maxn];
int l, r;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> l >> r;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		long long  ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int pl = lower_bound(a + i + 1, a + n, l - a[i]) - a;
			int pr = upper_bound(a + i + 1, a + n, r - a[i]) - a;
			ans += pr - pl;
		}
		cout << ans << endl;
	}
	return 0;
}