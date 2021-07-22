#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 5;
const int maxk = 505;
vector<int> G[maxn];

namespace cendec {

int ctr, sz[maxn], n;
int del[maxn];

void findroot(int u, int p = 0)
{
	sz[u] = 1;
	int maxsz = 0;
	for (int v : G[u]) {
		if (v != p && !del[v]) {
			findroot(v, u);
			if (ctr != -1) return;
			maxsz = max(maxsz, sz[v]);
			sz[u] += sz[v];
		}
	}
	maxsz = max(maxsz, n - sz[u]);
	if (maxsz <= n / 2) {
		sz[p] = n - sz[u];
		ctr = u;
	}
}

int k, res, tmp[maxn], cnt, lens[maxk];

void dfs(int u, int p, int len)
{
	if (len > k) return;
	res += lens[k - len] + (k == len);
	tmp[cnt++] = len;
	for (int v : G[u]) {
		if (v != p && !del[v]) {
			dfs(v, u, len + 1);
		}
	}
}

void solve(int u)
{
	for (int v : G[u]) {
		if (!del[v]) {
			cnt = 0;
			dfs(v, u, 1);
			for (int i = 0; i < cnt; i++) {
				lens[tmp[i]]++;
			}
		}
	}
	memset(lens, 0, sizeof(lens));
	del[u] = 1;
	for (int v : G[u]) {
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

}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << cendec::count(n, k) << endl;
	return 0;
}