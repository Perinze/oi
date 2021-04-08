#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50010;
int bit[MAXN + 1];
int n;

int sum(int i)
{
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x)
{
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        printf("Case %d:\n", cas);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", bit + i);
            if (i == 1) continue;
            int j = i - 1;
            for (int k = i; ~k & 1; k >>= 1) {
                bit[i] += bit[j];
                j -= j & -j;
            }
        }
        char cmd[6];
        int a, b;
        for (;;) {
            scanf("%s", cmd);
            if (cmd[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if (cmd[0] == 'A') add(a, b);
            else if (cmd[0] == 'S') add(a, -b);
            else if (cmd[0] == 'Q')
                printf("%d\n", sum(b) - sum(a - 1));
        }
    }
    return 0;
}