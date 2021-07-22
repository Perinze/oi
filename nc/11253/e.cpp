#include <bits/stdc++.h>
using namespace std;

#define foradj(e, v) for (int e = head[u], v = es[e].to; e; e = es[e].nxt, v = es[e].to)
using ll = long long;
const ll maxn = 1e5 + 5;
const ll maxq = 1e5 + 5;
ll n, q;
ll head[maxn], ecnt;
struct edge {
	ll to, cost;
	ll nxt;
	edge(ll v, ll w, ll prv): to(v), cost(w), nxt(prv) {}
	edge() {}
} es[maxn << 1];
ll a[maxn];
ll sz[maxn];
ll del[maxn];

ll qhead[maxn], qcnt;
struct query {
	ll x, d, p;
	ll nxt;
	query(ll x_, ll d_, ll p_, ll prv): x(x_), d(d_), p(p_), nxt(prv) {}
	query() {}
} qs[maxq];
ll ans[maxq];

void addedge(ll u, ll v, ll w)
{
	es[++ecnt] = edge(v, w, head[u]);
	head[u] = ecnt;
}

void addquery(ll x, ll d, ll p)
{
	qs[++qcnt] = query(x, d, p, qhead[x]);
	qhead[x] = qcnt;
}

void dfs(ll u, ll l, ll p = 0)
{
	if (l < 0) return;
	cout << "reach " << u << endl;
	cout << "with gas " << l << endl;
	sz[u] = 1;
	l += a[u];
	cout << "add gas to " << l << endl;
	foradj(e, v) {
		if (v != p && !del[v]) {
			dfs(v, l - es[e].cost, u);
			sz[u] += sz[v];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	// ecnt = 0;
	for (ll i = 0; i < n - 1; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	// qcnt = 0;
	for (ll i = 0; i < q; i++) {
		ll x, d, p;
		cin >> x >> d >> p;
		addquery(x, d, p);
		memset(sz, 0, sizeof(sz));
		dfs(x, d);
		cout << sz[x] - sz[p] << endl;
		cout << ' ' << sz[1] << endl;
	}
	/*
	for (ll u = 1; u <= n; u++) {
		for (ll i = qhead[u]; i; i = qs[i].nxt) {
			memset(sz, 0, sizeof(sz));
			dfs(qs[i].x, qs[i].d);
			cout << sz[qs[i].x] - sz[qs[i].p] << endl;
			//divcqr(qs[i].x, qs[i].d, qs[i].p);
		}
	}
	*/
	/*	
	for (ll i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
	*/
	return 0;
}