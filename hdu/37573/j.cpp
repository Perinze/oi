#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100010;
ll cbit[maxn];
ll sbit[maxn];
int n;
ll a[maxn];

void add(ll *bit, int i, ll x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x;
}

ll query(ll *bit, int i)
{
    ll sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    ll ans = 0;
    for (int i = n; i > 0; i--) {
        ans += query(cbit, a[i] - 1) * a[i] + query(sbit, a[i] - 1);
        add(cbit, a[i], 1);
        add(sbit, a[i], a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}