#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int n;
int a[maxn];
bitset<maxn> vis;

int main()
{
	cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		vis[a[i]] = 1;
	}
	for (int mod = n; mod <= mx + 1; mod++) {
		bool fail = false;
		for (int i = 0; i < n; i++) {
			for (int j = 1; ; j++) {
				int x = a[i] + j * mod;
				if (x > mx + 1) break;
				if (vis[x]) {
					fail = true;
					break;
				}
			}
			if (fail) break;
		}
		if (!fail) {
			cout << mod << endl;
			return 0;
		}
	}
	return 0;
}