#include <stdio.h>
#include <stdbool.h>

int N, k;
int par[150000], rnk[150000];

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
    scanf("%d %d", &N, &k);
    init(3 * N);
    int ans = 0;
    int cmd, x, y;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &cmd, &x, &y);
        x--; y--;
        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            ans++;
            continue;
        }
        if (cmd == 1)
        {
            if (same(x, y + N) || same(x, y + 2 * N))
            {
                ans++;
            }
            else
            {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        else
        {
            if (same(x, y) || same(x, y + 2 * N))
            {
                ans++;
            }
            else
            {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("%d", ans);
    return 0;
}