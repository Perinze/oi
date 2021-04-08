#include <iostream>
#include <cstdio>
using namespace std;
#define each(i, l, r) for (int i = l; i < r; i++)

const int INF = 2 << 31 - 1;
const int MAXN = 50000;
typedef pair<int, int> P;   // (height, pos)

int n, n_;
P dat[2 * MAXN - 1];
P ans[MAXN];

void init(int n_)
{
    each(i, 0, n_) ans[i] = P(0, 0);

    n = 1;
    while (n < n_) n *= 2;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        dat[i].first = -1;
        if (i >= n - 1) dat[i].second = i - n + 1;
    }
}

void update(int k, int a)
{
    k += n - 1;
    dat[k].first = a;
    while (k > 0)
    {
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

// query max value of [a, b) from [l, r)
// caint query(a, b, 0, 0, n)
P query(int a, int b, int k, int l, int r)
{
    if (r <= a || l >= b) return P(-1, -1);
    if (a <= l && r <= b) return dat[k];
    else
    {
        P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}

void route(int l, int r, int p)
{
    if (r - l <= 1) return;
    if (p > l)
    {
        int vl = query(l, p, 0, 0, n).second;
        ans[p].first = vl + 1;
        route(l, p, vl);
    }
    if (p < r - 1)
    {
        int vr = query(p + 1, r, 0, 0, n).second;
        ans[p].second = vr + 1;
        route(p + 1, r, vr);
    }
}

void solve(int case_id)
{
    scanf("%d", &n_);
    init(n_);
    int max_h = -1; int max_p;
    each(i, 0, n_) 
    {
        int a; scanf("%d", &a);
        update(i, a);
        if (a > max_h)
        {
            max_h = a;
            max_p = i;
        }
    }
    route(0, n_, max_p);
    printf("Case %d:\n", case_id);
    each(i, 0, n_) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) solve(t);
    return 0;
}