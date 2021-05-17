#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn];
int n;

int query(int t, int i, int j, int x)
{
    if (t == 1)
        return max(min(x, a[i]), min(x + 1, a[j]));
    else if (t == 2)
        return min(max(x, a[i]), max(x + 1, a[j]));
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int t, i, j, x;
    while (~scanf("%d%d%d%d", &t, &i, &j, &x)) {
        printf("%d\n", query(t, i, j, x));
    }
    return 0;
}