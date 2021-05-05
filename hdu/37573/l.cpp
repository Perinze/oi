#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 3000010;
const int maxa = 10010;
int n;
ll a[maxn];
ll bit[maxa];
ll ans;

void add(int i, ll x)
{
    for (; i <= maxa; i += i & -i)
        bit[i] += x;
}

ll query(int i)
{
    ll sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

void rotate(int l, int r)
{
    ll x = a[l];
    for (int i = l; i < r; i++) {
        a[i] = a[i + 1];
        if (a[i] < x) ans += 1;
        else if (a[i] > x) ans -= 1;
    }
    a[r] = x;
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        memset(bit, 0, sizeof(bit));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += query(a[i] - 1);
            add(a[i], 1);
        }
        int q;
        scanf("%d", &q);
        char cmd[2];
        while (q--) {
            scanf("%s", cmd);
            if (cmd[0] == 'Q')
                printf("%lld\n", ans);
            else {
                int l, r;
                scanf("%d%d", &l, &r);
                l++, r++;
                if (l > r) swap(l, r);
                rotate(l, r);
            }
        }
    }
    return 0;
}