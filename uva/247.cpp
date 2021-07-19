#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
bool g[maxn][maxn];
map<string, int> id;
string name[maxn];
vector<int> circle[maxn];
int n, m;
int cnt;

namespace uset {

int par[maxn], rnk[maxn];

void init(int n)
{
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

}

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n >> m && n && m) {
		id.clear();
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; i++) circle[i].clear();
		uset::init(n);
		cnt = 0;

		string a, b;
		while (m--) {
			cin >> a >> b;
			if (!id[a]) id[a] = ++cnt, name[cnt] = a;
			if (!id[b]) id[b] = ++cnt, name[cnt] = b;
			g[id[a]][id[b]] = true;
		}
		for (int i = 1; i <= n; i++) {
			g[i][i] = true;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] |= g[i][k] && g[k][j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (g[i][j] && g[j][i]) uset::unite(i, j);
			}
		}
		for (int i = 1; i <= n; i++) {
			circle[uset::find(i)].push_back(i);
		}
		if (kase) cout << endl;
		cout << "Calling circles for data set " << ++kase << ":" << endl;
		for (int i = 1; i <= n; i++) {
			if (!circle[i].empty()) {
				int l = circle[i].size();
				for (int j = 0; j < l; j++) {
					if (j) cout << ", ";
					cout << name[circle[i][j]];
				}
				cout << endl;
			}
		}
	}
	return 0;
}