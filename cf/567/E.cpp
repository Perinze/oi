#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int MAXV = 100001, MAXE = 100001;
const ll mod = 2860486313;

int s[MAXE];
int t[MAXE];
ll w[MAXE];
int nxt[MAXE];
int rnxt[MAXE];

int head[MAXV];
int rhead[MAXV];
int len = 1;

ll diss[MAXV];
ll dist[MAXV];
ll cnts[MAXV];
ll cntt[MAXV];
int V, E;
int S, T;

void add_edge(int u, int v, ll w_)
{
	s[len] = u;
	t[len] = v;
	w[len] = w_;
	nxt[len] = head[u];
	rnxt[len] = rhead[v];
	head[u] = len;
	rhead[v] = len;
	len++;
}

void dijkstra(int *to, int *nxt, int *head, ll *dis, ll *cnt, int s, ll mod)
{
	priority_queue<P, vector<P>, greater<P> > q;
	memset(dis, 0x3f, (V + 1) * sizeof(ll));
	dis[s] = 0;
	cnt[s] = 1;
	q.push(P(0, s));
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (dis[v] < p.first)
			continue;
		for (int i = head[v]; i != 0; i = nxt[i]) {
			int u = to[i];
			if (dis[u] == dis[v] + w[i])
				cnt[u] = (cnt[v] + cnt[u]) % mod;
			else if (dis[u] > dis[v] + w[i]) {
				cnt[u] = cnt[v];
				dis[u] = dis[v] + w[i];
				q.push(P(dis[u], u));
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &V, &E, &S, &T);
	for (int i = 0; i < E; i++) {
		int u, v;
		ll w_;
		scanf("%d%d%lld", &u, &v, &w_);
		add_edge(u, v, w_);
	}
	dijkstra(t, nxt, head, diss, cnts, S, mod);
	dijkstra(s, rnxt, rhead, dist, cntt, T, mod);

	for (int i = 1; i <= E; i++) {
		if (diss[s[i]] + w[i] + dist[t[i]] == diss[T] && cnts[s[i]] * cntt[t[i]] % mod == cnts[T])
			printf("YES\n");
		else {
			ll goal = diss[T];
			ll crt = diss[s[i]] + w[i] + dist[t[i]];
			if (crt - goal + 1 < w[i])
				printf("CAN %lld\n", crt - goal + 1);
			else
				printf("NO\n");
		}
	}

	return 0;
}
