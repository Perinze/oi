#include <bits/stdc++.h>
using namespace std;

const int maxn = 105 << 2;
const int inf = 0x3f3f3f3f;
string tmp;
map<string, int> devid;
map<string, int> plugid;
int cnt;
int n, m, k;
int ndev[maxn];

struct edge {
	int from, to, cap, flow;
	edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct edmonds_karp {
	int n, m;
	vector<edge> es;
	vector<int> G[maxn];
	int a[maxn];	// flow to be increase from s to i
	int p[maxn];	// in-edge in shortest path tree of i

	void init(int n) {
		for (int i = 0; i < n; i++) G[i].clear();
		es.clear();
	}

	void add_edge(int from, int to, int cap) {
		es.push_back(edge{from, to, cap, 0});
		es.push_back(edge{to, from, 0, 0});
		m = es.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	int maxflow(int s, int t) {
		int flow = 0;
		for (;;) {
			memset(a, 0, sizeof(a));
			queue<int> q;
			q.push(s);
			a[s] = inf;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int i = 0; i < G[u].size(); i++) {
					edge &e = es[G[u][i]];
					if (!a[e.to] && e.cap > e.flow) {
						p[e.to] = G[u][i];
						a[e.to] = min(a[u], e.cap - e.flow);
						q.push(e.to);
					}
				}
				if (a[t]) break;
			}
			if (!a[t]) break;
			for (int u = t; u != s; u = es[p[u]].from) {
				es[p[u]].flow += a[t];
				es[p[u] ^ 1].flow -= a[t];
			}
			flow += a[t];
		}
		return flow;
	}
} edk;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int cas = 0; cas < T; cas++) {
		cnt = 0;
		devid.clear();
		plugid.clear();
		memset(ndev, 0, sizeof(ndev));
		edk.init(maxn);

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			plugid[tmp] = i;
			edk.add_edge(0, i, 1);
		}
		cnt = n;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> tmp;
			cin >> tmp;
			if (!plugid[tmp]) {
				plugid[tmp] = ++cnt;
			}
			ndev[plugid[tmp]]++;
		}
		cin >> k;
		for (int i = 1; i <= k; i++) {
			int u, v;
			cin >> tmp;
			if (!plugid[tmp]) {
				plugid[tmp] = ++cnt;
			}
			u = plugid[tmp];
			cin >> tmp;
			if (!plugid[tmp]) {
				plugid[tmp] = ++cnt;
			}
			v = plugid[tmp];
			edk.add_edge(v, u, inf);
		}
		for (int i = 1; i <= n + m; i++) {
			if (ndev[i]) edk.add_edge(i, cnt + 1, ndev[i]);
		}
		if (cas) cout << endl;
		cout << m - edk.maxflow(0, cnt + 1) << endl;
	}
	return 0;
}