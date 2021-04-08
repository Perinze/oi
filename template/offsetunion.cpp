int par[MAXN], offset[MAXN];

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
    par[x] = find(x);
    offset[x] += offset[par[x]];
    return par[x];
}
