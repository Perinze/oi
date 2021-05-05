#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
struct Tree {
    ll x, h;
    int xr, hr;
} tree[maxn];
ll bit1[maxn];
ll bit2[maxn];

void add(ll *bit, int i, ll x)
{
    for (; i <= n; i += i & -i)
        bit[i] += x;
}

ll query(ll *bit, int i)
{
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

bool cmpx(const Tree &t1, const Tree &t2)
{
    if (t1.x == t2.x) return t1.h < t2.h;
    return t1.x < t2.x;
}

bool cmph(const Tree &t1, const Tree &t2)
{
    if (t1.h == t2.h) return t1.x < t2.x;
    return t1.h < t2.h;
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            ll x, h;
            scanf("%lld%lld", &x, &h);
            tree[i].x = x;
            tree[i].h = h;
        }
        ll tmp = -1;
        sort(tree + 1, tree + 1 + n, cmpx);
        for (int i = 1; i <= n; i++) {
            if (tree[i].x == tmp)
                tree[i].xr = tree[i - 1].xr;
            else
                tree[i].xr = i;
            tmp = tree[i].x;
        }
        tmp = -1;
        sort(tree + 1, tree + 1 + n, cmph);
        for (int i = 1; i <= n; i++) {
            if (tree[i].h == tmp)
                tree[i].hr = tree[i - 1].hr;
            else
                tree[i].hr = i;
            tmp = tree[i].h;
        }
        memset(bit1, 0, sizeof(bit1));
        memset(bit2, 0, sizeof(bit2));
        ll ans = 0, sum = 0; // sum of smaller rank
        for (int i = n; i > 0; i--) {
            ll ssr = query(bit1, tree[i].xr);   // sum of smaller rank
            ll ss = query(bit2, tree[i].xr);    // sum of smaller tree (x smaller)
            ans += tree[i].hr * (ss * tree[i].xr - ssr + sum - ssr - (n - i - ss) * tree[i].xr);
            sum += tree[i].xr;
            add(bit1, tree[i].xr, tree[i].xr);
            add(bit2, tree[i].xr, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}