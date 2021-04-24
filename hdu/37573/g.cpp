#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n;
int bit[maxn];

int query(int i)
{
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

void add(int i, int x)
{
    for (; i <= n; i += i & -i)
        bit[i] += x;
}

void add(int l, int r, int x)
{
    add(l, x), add(r + 1, -x);
}

int main()
{
    while (~scanf("%d", &n)) {
        if (!n) break;
        memset(bit, 0, sizeof(bit));
        int l, r;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &l, &r);
            add(l, r, 1);
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) putchar(' ');
            printf("%d", query(i));
        }
        puts("");
    }
    return 0;
}