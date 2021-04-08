#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100010, MAXM = 100010, MAXK = 510;

struct edge {
	int to, cost;
};
int n, m, k;
vector<edge> G[MAXN];
int hd[MAXK], c[MAXK];
int par[MAXN], rnk[MAXN];
int d[MAXK][MAXK];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		rnk[i] = 0;
	}
}

inline int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rnk[x] < rnk[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

inline bool same(int x, int y)
{
	return find(x) == find(y);
}

inline int typ(int x)
{
	for (int i = 1; i <= k; i++)
		if (x >= hd[i] && x < hd[i] + c[i]) return i;
	return 0;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int s = 1;
	for (int i = 1; i <= k; i++) {
		scanf("%d", c + i);
		hd[i] = s;
		s += c[i];
	}
	init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		G[u].push_back({v, x});
		G[v].push_back({u, x});
		if (!x)
			unite(u, v);
	}
	bool correct = true;
	for (int i = 1; i <= k; i++) {
		for (int j = hd[i] + 1; j < hd[i] + c[i]; j++) {
			correct &= same(hd[i], j);
			if (!correct) {
				puts("No");
				return 0;
			}
		}
	}
	puts("YES");
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
		for (int j = 0; j < (int)G[i].size(); j++) {
			int v = typ(i);
			int u = typ(G[i][j].to);
			int w = G[i][j].cost;
			d[v][u] = d[u][v] = min(d[v][u], w);
		}
	}
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			for (int l = 1; l <= k; l++)
				d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++)
			printf("%d ", d[i][j] == 0x3f3f3f3f ? -1 : d[i][j]);
		putchar('\n');
	}
	return 0;
}
