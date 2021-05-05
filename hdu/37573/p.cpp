#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll a[maxn];
ll bit[maxn];

void add(int i, ll x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x;
}

ll query(int i)
{
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

ll pre[maxn], aft[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            pre[i] = query(a[i]);
            add(a[i], 1);
        }
        memset(bit, 0, sizeof(bit));
        for (int i = n; i >= 1; i--) {
            aft[i] = query(a[i]);
            add(a[i], 1);
        }
        for (int i = 1; i <= n; i++)
            printf("%d %lld %lld\n", i, pre[i], aft[i]);
        ll ans = 0;
        for (int i = 2; i < n; i++) {
            ans += pre[i] * (n - i - aft[i]);
            printf("add %lld (inc)\n", pre[i] * (n - i - aft[i]));
            ans += aft[i] * (i - 1 - pre[i]);
            printf("add %lld (dec)\n", aft[i] * (i - 1 - pre[i]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}