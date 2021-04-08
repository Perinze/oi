#include <cstdio>

const int MAXN = 200001;
int par[MAXN], offset[MAXN];
int N, M;

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
        offset[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x) return x;
    int root = find(par[x]);
    offset[x] += offset[par[x]];
    return par[x] = root;
}

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
    init(MAXN);
    int ans = 0;
    while (M--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z); x--;
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
        {
            if (offset[x] - offset[y] != z) ans++;
        }
        else
        {
            par[rx] = ry;
            offset[rx] = offset[y] - offset[x] + z;
        }
    }
    printf("%d\n", ans);
    }
    return 0;
}