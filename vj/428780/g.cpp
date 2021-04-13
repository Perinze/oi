#include <cstdio>
#include <cstring>

#define MAXN 10010

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

inline bool side(int x)
{
	if (par[x] == -1) return -1;
	return kid[par[x]][1] == x;
}

inline void set_par(int k, int p, bool f)
{
	if (k != -1) par[k] = p;
	if (p != -1) kid[p][f] = k;
}

inline bool leaf(int x)
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
}

#ifdef debug
void print_tree(int x)
{
	if (x == -1)
	{
		return;
	}
	printf("%d -> %d, %d, size %d\n", val[x], val[kid[x][0]], val[kid[x][1]], size(x));
	print_tree(kid[x][0]);
	print_tree(kid[x][1]);
}
#endif

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
	while (par[x] != r)
	{
		if (par[par[x]] != -1 && side(par[x]) == side(x))
		{
			rotate(par[x]);
		}
		rotate(x);
	}
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
}

int kth(int k) // 1-ordered k
{
	int v = root;
	while (!leaf(v)) {
		int psm = size(kid[v][0]) + 1; // prefix middle size
		if (k < psm) {
			v = kid[v][0];
		} else if (k > psm) {
			v = kid[v][1];
			k -= psm;
		} else {
			goto ret;
		}
	}
	ret:
	splay(v, -1);
	return v;
}

int flag;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        flag = 0;
        int cas, n;
        scanf("%d%d", &cas, &n);
        printf("%d %d\n", cas, n / 2 + 1);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            insert(x);
            if (i % 2) {
                printf("%d", val[kth(i / 2 + 1)]);
                ++flag;
                if (flag == 10) putchar('\n'), flag = 0;
                else putchar(' ');
            }
        }
        if (flag) putchar('\n');
    }
    return 0;
}