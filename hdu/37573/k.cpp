#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int maxn = 1000010;
int n;
P a[maxn];
int b[maxn];
ll bit[maxn];

void add(int i, ll x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x;
}

ll query(int i)
{
    ll sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            ll x;
            scanf("%lld", &x);
            a[i] = P(x, i);
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            b[i] = a[i].second;
            //b[a[i].second] = i;
        ll ans = 0;
        //for (int i = n; i > 0; i--) {
        for (int i = n; i > 0; i--) {
            ans += query(b[i] - 1);
            add(b[i], 1);
        }
        /*
        for (int i = 1; i <= n; i++) {
            add(b[i], 1);
            ans += i - query(b[i]);
        }
        */
        printf("%lld\n", ans);
    }
    return 0;
}