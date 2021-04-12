#include <iostream>
#include <cstring>
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
using namespace std;

const int MAXN = 20;

int par[MAXN];
int kid[MAXN][2];
int val[MAXN];
int root, size;

void init()
{
	memset(par, -1, sizeof(par));
	memset(kid, -1, sizeof(kid));
	memset(val, -1, sizeof(val));
	root = -1;
	size = 0;
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

void print_array()
{
	debug("print array\n");
	for (int i = 0; i < size; i++) debug("%d\t", par[i]);
	debug("\n");
	for (int i = 0; i < size; i++) debug("%d, %d\t", kid[i][0], kid[i][1]);
	debug("\n");
	for (int i = 0; i < size; i++) debug("%d\t", val[i]);
	debug("\n\n");
}

void print_tree(int x)
{
	if (x == -1)
	{
		return;
	}
	debug("%d -> %d, %d\n", val[x], val[kid[x][0]], val[kid[x][1]]);
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
		g = gp;
	}

	single:
	set_par(v, g, side(p));
	set_par(kid[v][!f], p, f);
	set_par(p, v, !f);

	if (par[v] == -1) root = v;
}

void splay(int x)
{
	debug("splay(%d)\n", x);
	while (par[x] != -1)
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
	int i = size++;
	val[i] = x;
	if (root == -1)
	{
		root = i;
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

	debug("after insert(%d)\n", x);
	print_tree(root);
	debug("\n");

	splay(i);
	debug("after splay(%d)\n", x);
	print_tree(root);
	debug("\n");
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
	return 0;
}
