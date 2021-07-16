#include <bits/stdc++.h>
using namespace std;

const int maxn = 105 << 2;
const int inf = 0x3f3f3f3f;
struct edge {
	int from, to, cap, flow;
	edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};
void init();
void input();
string tmp, tmp1;

struct edmonds_karp {
	int V, E;
	vector<edge> es;
	vector<int> G[maxn];
	int a[maxn];
	int p[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) G[i].clear();
		es.clear();
	}
	void add_edge(int from, int to, int cap) {
		es.push_back(edge{from, to, cap, 0});
		es.push_back(edge{to, from, 0, 0});
		E = es.size();
		G[from].push_back(E - 2);
		G[to].push_back(E - 1);
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

map<string, int> recid;
map<string, int> devid;

int cnt;
int dev[maxn];
int rec[maxn];
int adapter[maxn][2];
int n, m, k;

int g[maxn][maxn];

int main()
{
	ios::sync_with_stdio(false);
	int cas;
	cin >> cas;
	for (int kas = 0; kas < cas; kas++) {
		init();
		input();
		for (int i = 1; i <= cnt; i++) g[i][i] = true;
		for (int k = 1; k <= cnt; k++)
			for (int i = 1; i <= cnt; i++)
				for (int j = 1; j <= cnt; j++)
					g[i][j] |= g[i][k] && g[k][j];
		edk.init(n + m + 2);
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= m; v++) {
				// if (g[rec[u]][dev[v]])
				if (g[u][dev[v]]) {
					edk.add_edge(u, n + v, inf);
				}
			}
		}
		for (int i = 1; i <= n; i++) edk.add_edge(0, i, 1);
		for (int i = 1; i <= m; i++) edk.add_edge(n + i, n + m + 1, 1);
		int ans = m - edk.maxflow(0, n + m + 1);
		if (kas) cout << endl;
		cout << ans << endl;
	}
	return 0;
}

void init()
{
	cnt = 0;
	recid.clear();
	devid.clear();
	memset(g, 0, sizeof(g));
}

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (!recid[tmp]) {
			recid[tmp] = ++cnt;
		}
		rec[i] = recid[tmp];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		if (!devid[tmp]) {
			devid[tmp] = i;
		}
		cin >> tmp;
		if (!recid[tmp]) {
			recid[tmp] = ++cnt;
		}
		dev[i] = recid[tmp];
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int u, v;
		cin >> tmp;
		if (!recid[tmp]) {
			recid[tmp] = ++cnt;
		}
		adapter[i][0] = u = recid[tmp];
		cin >> tmp;
		if (!recid[tmp]) {
			recid[tmp] = ++cnt;
		}
		adapter[i][1] = v = recid[tmp];
		g[v][u] = true;
	}
}