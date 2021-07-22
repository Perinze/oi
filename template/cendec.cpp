#define foradj(e, v) for (int e = head[u], v = es[e].to; e; e = es[e].nxt, v = es[e].to)

int head[maxn];
struct edge {
	int u, v, w;
	int nxt;
} es[maxm];
int n, m;

namespace cendec {

int ctr, sz[maxn];
int del[maxn];
int vcnt;

void findroot(int u, int p = 0)
{
	sz[u] = 1;
	int maxsz = 0;
	foradj(e, v) {
		if (!del[v] && v != p) {
			findroot(v, u);
			if (ctr != -1) return;
			maxsz = max(maxsz, sz[v]);
			sz[u] += sz[v];
		}
	}
	maxsz = max(maxsz, n - sz[u]);
	if (maxsz <= vcnt / 2) {
		ctr = u;
		sz[p] = vcnt - sz[u];
	}
}

int k, tmp[maxn], cnt, res, lens[maxk];

void dfs(int u, int p, int len)
{
	if (len > k) return;
	res += lens[k - len] + (len == k);
	tmp[cnt++] = len;
	foradj(e, v) {
		if (!del[v] && v != p) {
			dfs(v, u, len + 1);
		}
	}
}

void solve(int u)
{
	foradj(e, v) {
		if (!del[v]) {
			dfs(v, u, 1);
			for (int i = 0; i < cnt; i++) {
				len[tmp[i]]++;
			}
			cnt = 0;
		}
	}
	memset(lens, 0, sizeof(lens));
	del[u] = 1;
	foradj(e, v) {
		if (!del[v]) {
			n = sz[v];
			ctr = -1;
			findroot(v);
			solve(ctr);
		}
	}
}

int count(int n_, int k_)
{
	n = n_, k = k_, ctr = -1;
	findroot(1);
	solve(ctr);
	return res;
}

} // namespace cendec