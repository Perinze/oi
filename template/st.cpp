int a[maxn];
int st[maxn][logmaxn];
int n, logn;

void stinit(int n)
{
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int i = 1; i <= logn; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
}

int stquery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}