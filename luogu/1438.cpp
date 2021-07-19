#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)

using ll = long long;
const int maxn = 1e5 + 5;

int dat[maxn << 2], lazy[maxn << 2];
int n;
int a[maxn], diff[maxn];

void init(int m)
{
	n = 1;
	while (n < m) n <<= 1;
}

void pushup(int k)
{
	dat[k] = dat[ls] + dat[rs];
}

void pushdown(int k)
{
	if (k < n - 1) {
		lazy[ls] += lazy[k];
		lazy[rs] += lazy[k];
	}
	lazy[k] = 0;
}

void build(int a, int b, int k, int l, int r)
{
	if (l + 1 == r) {
		dat[k] = diff[k - n + 1];
		return;
	}
	build(a, b, ls, l, (l + r) >> 1);
	build(a, b, rs, (l + r) >> 1, r);
	pushup(k);
}

void update(int a, int b, int x, int k, int l, int r)
{
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {
		lazy[k] += x;
		return;
	}
	dat[k] += (min(b, r) - max(a, l)) * x;
	update(a, b, x, ls, l, (l + r) >> 1);
	update(a, b, x, rs, (l + r) >> 1, r);
}

int query(int a, int b, int k, int l, int r)
{
	if (r <= a || b <= l) return 0;
	if (lazy[k]) {
		dat[k] += (r - l) * lazy[k];
		pushdown(k);
	}
	if (a <= l && r <= b) return dat[k];
	int vl = query(a, b, ls, l, (l + r) >> 1);
	int vr = query(a, b, rs, (l + r) >> 1, r);
	return vl + vr;
}

int main()
{
	int m, q;
	scanf("%d%d", &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", a + i);
		diff[i - 1] = a[i] - a[i - 1];
	}
	init(m);
	build(0, n, 0, 0, n);

	int cmd, l, r, k, d;
	while (q--) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d%d%d%d", &l, &r, &k, &d);
			l--, r--;
			update(l, l + 1, k, 0, 0, n);
			if (l + 1 < n) update(l + 1, min(r + 1, n), d, 0, 0, n);
			if (r + 1 < n) update(r + 1, r + 2, -k - (r - l) * d, 0, 0, n);
		} else {
			scanf("%d", &k);
			printf("%d\n", query(0, k, 0, 0, n));
		}
	}
	return 0;
}