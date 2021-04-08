#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50010;

int dat[4 * MAXN];
int n;

void init(int n_)
{
    n = 1;
    while (n < n_)
        n *= 2;
    memset(dat, 0, sizeof(dat));
}

void update(int k, int x)
{
    k += n - 1;
    dat[k] += x;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] += x;
    }
}

int query(int a, int b, int k, int l, int r)
{
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return dat[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        printf("Case %d:\n", cas);
        int m;
        scanf("%d", &m);
        init(m);
        for (int i = 0; i < m; i++)
            scanf("%d", dat + i + n - 1);
        for (int i = n - 2; i >= 0; i--)
            dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
        char cmd[6];
        int a, b;
        for (;;) {
            /*
            for (int i = 0; i < 2 * n - 1; i++)
                printf("%d ", dat[i]);
            putchar('\n');
            */
            scanf("%s", cmd);
            if (cmd[0] == 'E') break;
            scanf("%d%d", &a, &b);
            a--;
            if (cmd[0] == 'Q')
                printf("%d\n", query(a, b, 0, 0, n));
            else if (cmd[0] == 'A')
                update(a, b);
            else if (cmd[0] == 'S')
                update(a, -b);
            else {
                fputs("unknown command\n", stderr);
                return 1;
            }
        }
    }
    return 0;
}