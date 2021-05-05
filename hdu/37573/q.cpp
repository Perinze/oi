#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int maxa = 100000;
int a[maxn];
int bit[maxn];

void add(int i, int x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x;
}

int query(int i)
{
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

int main()
{
    int m;
    while (~scanf("%d", &m)) {
        memset(a, 0, sizeof(a));
        memset(bit, 0, sizeof(bit));
        while (m--) {
            int cmd, x, k;
            scanf("%d", &cmd);
            switch (cmd) {
                case 0:
                scanf("%d", &x);
                a[x]++;
                add(x, 1);
                break;
                case 1:
                scanf("%d", &x);
                if (a[x] <= 0) {
                    puts("No Elment!");
                    break;
                }
                a[x]--;
                add(x, -1);
                break;
                case 2:
                scanf("%d%d", &x, &k);
                if (query(maxa) - query(x) < k) {
                    puts("Not Find!");
                    break;
                }
                int l = 0, r = maxa;
                int res;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (query(mid) - query(x) >= k) {
                        res = mid;
                        r = mid - 1;
                    } else
                        l = mid + 1;
                }
                printf("%d\n", res);
            }
        }
    }
    return 0;
}