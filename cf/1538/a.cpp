#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n;
int a[maxn];
int pre[maxn];

int main()
{
	int t;
    cin >> t;
    while (t--) {
		cin >> n;
		int mx = 0, pmx, mn = 1000, pmn;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] > mx) {
				mx = a[i], pmx = i;
			}
			if (a[i] < mn) {
				mn = a[i], pmn = i;
			}
		}
		int ans[4];
		ans[0] = max(pmx, pmn);
		ans[1] = n - min(pmx, pmn) + 1;
		ans[2] = pmx + n - pmn + 1;
		ans[3] = pmn + n - pmx + 1;
		sort(ans, ans + 4);
		cout << ans[0] << endl;
    }
	return 0;
}