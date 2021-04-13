#include <iostream>
#include <cstring>
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
using namespace std;

const int MAXN = 20;

int par[MAXN];
int kid[MAXN][2];
int siz[MAXN];
int root, cnt;
int val[MAXN];

void init()
{
	memset(par, -1, sizeof(par));
	memset(kid, -1, sizeof(kid));
	memset(val, -1, sizeof(val));
	memset(siz, 0, sizeof(siz));
	root = -1;
	cnt = 0;
}

bool side(int x)
{
	if (par[x] == -1)
	{
		debug("\nerr: %d has no parent\n\n", x);
	}
	return kid[par[x]][1] == x;
}

void set_par(int k, int p, bool f)
{
	if (k != -1) par[k] = p;
	if (p != -1) kid[p][f] = k;
}

bool leaf(int x)
{
	return kid[x][0] == -1 && kid[x][1] == -1;
}

inline int size(int v)
{
	return v == -1 ? 0 : siz[v];
}

inline void resize(int v)
{
	siz[v] = 1 + (kid[v][0] == -1 ? 0 : siz[kid[v][0]]) + (kid[v][1] == -1 ? 0 : siz[kid[v][1]]);
	debug("resize: set %d to %d\n", v, siz[v]);
}

void print_array()
{
	debug("print array\n");
	for (int i = 0; i < cnt; i++) debug("%d\t", par[i]);
	debug("\n");
	for (int i = 0; i < cnt; i++) debug("%d, %d\t", kid[i][0], kid[i][1]);
	debug("\n");
	for (int i = 0; i < cnt; i++) debug("%d\t", val[i]);
	debug("\n\n");
}

void print_tree(int x)
{
	if (x == -1)
	{
		return;
	}
	debug("%d -> %d, %d, size %d\n", val[x], val[kid[x][0]], val[kid[x][1]], size(x));
	print_tree(kid[x][0]);
	print_tree(kid[x][1]);
}

void rotate(int v)
{
	bool f = side(v);
	int p = par[v];
	bool pf = side(p);
	int g = par[p];

	if (g == -1) {
		goto single;
	}

	if (f == pf) {
		int gp = par[g];
		set_par(p, gp, side(g));
		set_par(kid[p][!pf], g, pf);
		set_par(g, p, !pf);
		resize(g);
		resize(p);
		g = gp;
	}

	single:
	set_par(v, g, side(p));
	set_par(kid[v][!f], p, f);
	set_par(p, v, !f);
	resize(p);
	resize(v);

	if (par[v] == -1) root = v;
}

void splay(int x, int r) // for splay to root use r = -1
{
	debug("splay(%d)\n", x);
	while (par[x] != r)
	{
		if (par[par[x]] != -1 && side(par[x]) == side(x))
		{
			debug("rotate(%d)\n", par[x]);
			rotate(par[x]);
		}
		debug("rotate(%d)\n", x);
		rotate(x);
	}
	debug("\n");
}

void insert(int x)
{
	int i = cnt++;
	val[i] = x;
	if (root == -1)
	{
		root = i;
		siz[i] = 1;
		return;
	}

	int j = root, p = root;
	for (;;)
	{
		j = kid[j][x > val[j]];
		if (j == -1) break;
		p = j;
	}
	set_par(i, p, x > val[p]);
	siz[i] = 1;
	for (j = par[i]; j != -1; j = par[j]) {
		resize(j);
	}

	debug("after insert(%d)\n", x);
	print_tree(root);
	debug("\n");

	splay(i, -1);
	debug("after splay(%d)\n", x);
	print_tree(root);
	debug("\n");
}

int kth(int k) // 1-ordered k
{
	debug("find(%d)\n", k);
	int v = root;
	while (!leaf(v)) {
		int psm = size(kid[v][0]) + 1; // prefix middle size
		debug("??? siz[%d] = %d\n", kid[v][0], size(kid[v][0]));
		debug("now %d, psm %d\n", val[v], psm);
		if (k < psm) {
			v = kid[v][0];
			debug("left\n");
		} else if (k > psm) {
			v = kid[v][1];
			k -= psm;
			debug("right\n");
		} else {
			debug("found\n");
			goto ret;
		}
	}
	ret:
	splay(v, -1);
	return v;
}

int main()
{
	init();
	insert(7);
	puts("");
	insert(1);
	puts("");
	insert(4);
	puts("");
	insert(8);
	puts("");
	insert(3);
	puts("");
	insert(9);
	puts("");
	insert(5);
	puts("");
	insert(2);
	puts("");
	insert(6);
	puts("");
	insert(0);
	puts("");
	splay(4, 1);
	debug("after splay(%d, %d)\n", 4, 1);
	print_tree(root);
	debug("\n");
	for (int i = 1; i <= 9; i++) {
		print_tree(root);
		debug("%dth: %d\n", i, val[kth(i)]);
	}
	return 0;
}
