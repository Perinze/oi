#include <iostream>
#include <cstring>
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
		cout << "No parent error" << endl;
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
	for (int i = 0; i < size; i++) cout << par[i] << ' ';
	cout << endl;
	for (int i = 0; i < size; i++) cout << kid[i][0] << ',' << kid[i][1] << ' ';
	cout << endl;
	for (int i = 0; i < size; i++) cout << val[i] << ' ';
	cout << endl;
}

void print_tree(int x)
{
	if (x == -1)
	{
		return;
	}
	cout << val[x] << " -> " << val[kid[x][0]] << ", " << val[kid[x][1]] << endl;
	print_tree(kid[x][0]);
	print_tree(kid[x][1]);
}

void rotate(int x)
{
	bool f = side(x);
	int y = par[x];
	int z = par[y];

	set_par(x, z, side(y));
	set_par(kid[x][!f], y, f);
	set_par(y, x, !f);

	if (par[x] == -1) root = x;
}

bool debug = true;
void splay(int x)
{
	if (val[x] == 4) debug = true;
	while (par[x] != -1)
	{
		if (par[par[x]] != -1 && side(par[x]) == side(x))
		{
			if (debug) cout << "rotate(" << par[x] << ")\n";
			rotate(par[x]);
		}
		if (debug) cout << "rotate(" << x << ")\n";
		rotate(x);
	}
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

	cout << "after insert\n";
	print_tree(root);

	splay(i);
	cout << "after splay\n";
	print_tree(root);
}

int main()
{
	init();
	insert(7);
	getchar();
	insert(1);
	getchar();
	insert(4);
	getchar();
	insert(8);
	getchar();
	insert(3);
	getchar();
	insert(9);
	getchar();
	insert(5);
	getchar();
	insert(2);
	getchar();
	insert(6);
	getchar();
	insert(0);
	return 0;
}
