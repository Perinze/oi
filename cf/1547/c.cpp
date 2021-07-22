#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int maxn = 305;
int k, n, m;
int a[maxn], b[maxn];
int pa, pb;
int ans[maxn << 1];
int cnt;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		pa = 0, pb = 0;
		cnt = 0;
		while (pa < n || pb < m) {
			if (pa < n && a[pa] == 0) {
				ans[cnt++] = a[pa];
				pa++;
				k++;
			} else if (pb < m && b[pb] == 0) {
				ans[cnt++] = b[pb];
				pb++;
				k++;
			} else if (pa < n && a[pa] <= k) {
				ans[cnt++] = a[pa];
				pa++;
			} else if (pb < m && b[pb] <= k) {
				ans[cnt++] = b[pb];
				pb++;
			} else {
				break;
			}
		}
		if (pa < n || pb < m) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < cnt; i++)
				cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}