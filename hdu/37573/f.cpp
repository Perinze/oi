#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50010;
int pre[maxn];
int bit[maxn];
int n;

void add(int i, int x)
{
    for (; i <= n; i += i & -i)
        bit[i] += x;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", pre + i);
            pre[i] += pre[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            bit[i] = pre[i] - pre[i - (i & -i)];
        }
        printf("Case %d:\n", cas);
        char cmd[6];
        while (~scanf("%s", cmd)) {
            if (!strcmp(cmd, "End")) break;
            int a, b;
            scanf("%d%d", &a, &b);
            if (!strcmp(cmd, "Add"))
                add(a, b);
            else if (!strcmp(cmd, "Sub"))
                add(a, -b);
            else
                printf("%d\n", query(b) - query(a - 1));
        }
    }
    return 0;
}