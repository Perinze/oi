#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

int dat[4 * MAXN];
int n;

void init(int n_)
{
    n = 1;
    while (n < n_) n *= 2;
    memset(dat, -1, sizeof(dat));
}

void update(int k, int x)
{
    k += n - 1;
    dat[k] = x;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return -1;
    if (a <= l && r <= b) return dat[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
}

int main()
{
    int m, q;
    while (~scanf("%d%d", &m, &q)) {
        init(m);
        for (int i = 0; i < m; i++)
            scanf("%d", dat + n - 1 + i);
        for (int i = n - 2; i >= 0; i--)
            dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
        char cmd[2];
        int a, b;
        while (q--) {
            scanf("%s%d%d", cmd, &a, &b);
            a--;
            if (cmd[0] == 'Q')
                printf("%d\n", query(a, b, 0, 0, n));
            else if (cmd[0] == 'U')
                update(a, b);
            else {
                fputs("unknown command\n", stderr);
                return 1;
            }
        }
    }
    return 0;
}