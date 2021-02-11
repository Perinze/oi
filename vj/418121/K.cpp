#include <cstdio>

const int MAXN = 1000;
int par[MAXN], rnk[MAXN];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
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

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            unite(x, y);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (par[i] == i) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}