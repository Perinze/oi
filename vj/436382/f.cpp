#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 110;

int par[maxn], rnk[maxn];
int n, m;

struct edge {
    int v, u, w;
    edge (int v, int u, int w): v(v), u(u), w(w) {}
    bool operator<(const edge& s) {
        return w < s.w;
    }
};
vector<edge> es;
vector<int> mst;

void init(int n)
{
	for (int i = 0; i < n; i++) {
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
	x = find(x);
	y = find(y);
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

int kruskal(int del, bool record)
{
    init(n);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < es.size(); i++) {
        if (i == del) continue;
        //printf("%d ", i);
        if (!same(es[i].v, es[i].u)) {
            unite(es[i].v, es[i].u);
            if (record) mst.push_back(i);
            ans += es[i].w;
            cnt++;
        }
    }
    //puts("");
    return cnt == n - 1 ? ans : -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        es.clear();
        mst.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int v, u, w;
            scanf("%d%d%d", &v, &u, &w);
            v--, u--;
            es.push_back(edge(v, u, w));
        }
        sort(es.begin(), es.end());
        int ans = kruskal(-1, true);
        //printf("mst size %d\n", ans);
        for (int i = 0; i < mst.size(); i++) {
            int del = mst[i];
            int res = kruskal(del, false);
            //printf("%d %d\n", del, res);
            if (ans == res) {
                ans = -1;
                break;
            }
        }
        if (ans == -1) puts("Not Unique!");
        else printf("%d\n", ans);
    }
    return 0;
}