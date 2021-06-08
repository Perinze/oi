#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 10;

ll dat[maxn * 4];
int arr[maxn];
ll n;

void init(ll m)
{
    n = 1;
    while (n < m) n <<= 1;
}

void build(ll a, ll b, ll k, ll l, ll r)
{
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1];
        return;
    }
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
    dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
}

void update(ll k, ll x)
{
    k += n - 1;
    dat[k] += x;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] += x;
    }
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
}

int main()
{
    int t;
    scanf("%d", &t);
    int kase = 1;
    while (t--) {
        memset(dat, 0, sizeof(dat));
        memset(arr, 0, sizeof(arr));
        int m;
        scanf("%d", &m);
        init(m);
        for (int i = 0; i < m; i++)
            scanf("%d", arr + i);
        build(0, m, 0, 0, n);
        printf("Case %d:\n", kase++);
        char tmp[10];
        int a, b;
        while (~scanf("%s", tmp) && tmp[0] != 'E') {
            scanf("%d%d", &a, &b);
            if (tmp[0] == 'Q')
                printf("%lld\n", query(a - 1, b, 0, 0, n));
            else if (tmp[0] == 'A')
                update(a - 1, b);
            else
                update(a - 1, -b);
        }
    }
    return 0;
}