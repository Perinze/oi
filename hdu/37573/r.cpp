#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int mod = 9901;
int n, h;
int seq[maxn];
int num[maxn];
int bit[maxn];

void add(int i, int x)
{
    for (; i <= n; i += i & -i)
        bit[i] = (bit[i] + x) % mod;
}

int query(int i)
{
    int s = 0;
    for (; i > 0; i -= i & -i)
        s = (s + bit[i]) % mod;
    return s;
}

int main()
{
    while (~scanf("%d%d", &n, &h)) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            scanf("%d", seq + i);
            num[i] = seq[i];
        }
        int ans = 0;
        sort(num + 1, num + 1 + n);
        int cnt = unique(num + 1, num + 1 + n) - num - 1;
        for (int i = 1; i <= n; i++) {
            int p1 = lower_bound(num + 1, num + 1 + cnt, seq[i] - h) - num - 1;
            int p2 = upper_bound(num + 1, num + 1 + cnt, seq[i] + h) - num - 1;
            int x = query(p2) - query(p1);
            x = (x % mod + mod) % mod;
            ans = (ans + x) % mod;
            int p = lower_bound(num + 1, num + 1 + cnt, seq[i]) - num;
            add(p, x + 1);
        }
        printf("%d\n", ans % mod);
    }
    return 0;
}