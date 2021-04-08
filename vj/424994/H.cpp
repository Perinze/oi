#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN_ = 110, MAXN = 100010, MAXM = 100010;
int n, n_, m;
bool dp[MAXM];
int w[MAXN];
int a[MAXN_], c[MAXN_];

int main()
{
	while (~scanf("%d%d", &n_, &m) && n_ && m) {
		for (int i = 1; i <= n_; i++) scanf("%d", a + i);
		for (int i = 1; i <= n_; i++) scanf("%d", c + i);
		n = 0;
		for (int i = 1; i <= n_; i++) {
			int x = 1;
			while (c[i] - x >= 0) {
				w[++n] = x * a[i];
				c[i] -= x;
				x *= 2;
			}
			if (c[i])
				w[++n] = c[i] * a[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= w[i]; j--)
				if (!dp[j] && dp[j - w[i]]) {
					dp[j] = 1;
					ans++;
				}
		printf("%d\n", ans);
	}
	return 0;
}
