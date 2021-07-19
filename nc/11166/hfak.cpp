#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

int n;
int a[maxn];
bool vis[maxn];

int C(int mod)
{
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i] % mod;
		if (vis[x]) ans++;
		vis[x] = true;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	int l = 1, r = maxn;
	int ans;
	while (l <= r) {
		int md = (l + r) / 2;
		if (C(md)) l = md + 1;
		else {
			r = md - 1;
			ans = md;
		}
	}
	printf("%d\n", ans);
	return 0;
}