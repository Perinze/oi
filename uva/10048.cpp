#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxm = 1005;
int g[maxn][maxn];
int n, m, q;

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n >> m >> q && n) {
		memset(g, 0x3f, sizeof(g));
		int u, v, w;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			g[u][v] = g[v][u] = w;
		}
		for (int i = 1; i <= n; i++) g[i][i] = 0;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
				}
			}
		}
		if (kase) cout << endl;
		cout << "Case #" << ++kase << endl;
		while (q--) {
			cin >> u >> v;
			if (g[u][v] >= 0x3f3f3f3f) cout << "no path" << endl;
			else cout << g[u][v] << endl;
		}
	}
}