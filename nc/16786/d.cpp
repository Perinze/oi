#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
struct edge {
	ll to, cost;
};
const ll maxn = 100010;
ll n, m, s, t;
vector<edge> G[maxn * 3];
ll d[maxn * 3];
ll typ[maxn];

inline void add_edge(ll from, ll to, ll dist)
{
	if (typ[from] == 3 && typ[to] == 3) {
		G[from].push_back({to, dist});
		G[from + n].push_back({to + n, dist});
		G[from + n * 2].push_back({to + n * 2, dist});
	}
	if (typ[from] == 3 && typ[to] == 1)
		G[from].push_back({to + n, dist});
	if (typ[from] == 3 && typ[to] == 2)
		G[from + n].push_back({to + n * 2, dist});
	if (typ[from] == 1 && typ[to] == 2)
		G[from + n].push_back({to + n * 2, dist});
	if (typ[from] == 1 && typ[to] == 3)
		G[from + n].push_back({to + n, dist});
	if (typ[from] == 2 && typ[to] == 3)
		G[from + n * 2].push_back({to + n * 2, dist});
}

void dijkstra(ll s)
{
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll(0, s));
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	while (!q.empty()) {
		pll p = q.top();
		q.pop();
		ll u = p.second;
		if (d[u] < p.first) continue;
		for (edge &e : G[u]) {
			if (d[e.to] > d[u] + e.cost) {
				d[e.to] = d[u] + e.cost;
				q.push(pll(d[e.to], e.to));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	for (ll i = 1; i <= n; i++) {
		cin >> typ[i];
	}
	ll from, to, dist;
	for (ll i = 1; i <= m; i++) {
		cin >> from >> to >> dist;
		add_edge(from, to, dist);
	}
	dijkstra(s);
	ll ans = d[t + n * 2];
	cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << endl;
	return 0;
}