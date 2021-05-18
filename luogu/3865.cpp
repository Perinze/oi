#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const int logmaxn = 20;

int a[maxn];
int st[maxn][logmaxn];
int n, logn;
int m;

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
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d%d", &n, &m);
    logn = log2(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    stinit(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", stquery(l, r));
    }
    return 0;
}