#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (int)l; i < (int)r; i++)
using namespace std;
const int maxn = 4e5 + 5;

vector<int> g[maxn];
set<int> s[2];
int n, m;

void dfs(int u, vector<int> &color, bool use_s) {
	color[u] = 1;
	for (int v : g[u]) {
		if (color[v] == 0)
			dfs(v, color, use_s);
		else if (use_s)
			s[color[v] - 1].insert(v);
	}	
	color[u] = 2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		rep(i, 0, n) g[i].clear();
		vector<int> cc[2];
		rep(i, 0, 2) {
			cc[i].resize(n);
			s[i].clear();
		}
		rep(i, 0, m) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
		}
		vector<int> color(n);
		dfs(0, color, 1);
		rep(i, 0, 2) {
			for (int u : s[i]) {
				dfs(u, cc[i], 0);
			}
		}
		rep(u, 0, n) {
			int ans;
			if (!color[u]) ans = 0;
			else if (cc[0][u]) ans = -1;
			else if (cc[1][u]) ans = 2;
			else ans = 1;
			cout << ans << ' ';
		}
		cout << endl;
	}
	ios::sync_with_stdio(false);
	return 0;
}