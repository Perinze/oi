#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int maxn = 1 << 20 + 5;
const int maxbug = 25;
const int maxpatch = 105;
const int inf = 0x3f3f3f3f;

int n, m, n_;
char pat[maxpatch][2][maxbug];
int tim[maxn];
int d[maxn];

bool patch(int u, int &v, int idx)
{
	char *pl = pat[idx][0];
	char *pr = pat[idx][1];
	int cu = u;
	for (int i = 0; i < n_; i++) {
		if (pl[i] == '-' && (cu & 1)) return false;
		if (pl[i] == '+' && (~cu & 1)) return false;
		cu >>= 1;
	}
	v = 0;
	for (int i = 0; i < n_; i++) {
		if (pr[i] == '+' || (pr[i] == '0' && ((u >> i) & 1))) {
			v |= (1 << i);
		}
	}
	//printf("%d -> %d, %s, %s\n", u, v, pl, pr);
	return true;
}

void dijkstra(int s)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	q.push(pii(0, s));
	while (!q.empty()) {
		pii p = q.top(); q.pop();
		int u = p.second;
		if (d[u] < p.first) continue;
		int v, w;
		for (int i = 0; i < m; i++) {
			if (!patch(u, v, i) || u == v) continue;
			w = tim[i];
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(pii(d[v], v));
			}
		}
	}
}

int main()
{
	int kase = 0;
	while (~scanf("%d%d", &n_, &m) && n_) {
		n = 1 << n_;
		for (int i = 0; i < m; i++) {
			scanf("%d%s%s", tim + i, pat[i][0], pat[i][1]);
		}
		int s = n - 1, t = 0;
		dijkstra(s);
		printf("Product %d\n", ++kase);
		if (d[t] >= inf) printf("Bugs cannot be fixed.\n\n");
		else printf("Fastest sequence takes %d seconds.\n\n", d[t]);
	}
	return 0;
}