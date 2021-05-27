#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
struct node {
    int smax, sum, lmax, rmax;
    node() {
        smax = -inf, sum = 0, lmax = -inf, rmax = -inf;
    }
} dat[maxn * 4];
int arr[maxn];
int n;

void init(int m)
{
    n = 1;
    while (n < m) n *= 2;
}

void pushup(int k)
{
    dat[k].smax = max(max(dat[ls].smax, dat[rs].smax), dat[ls].rmax + dat[rs].lmax);
    dat[k].sum = dat[ls].sum + dat[rs].sum;
    dat[k].lmax = max(dat[ls].lmax, dat[ls].sum + dat[rs].lmax);
    dat[k].rmax = max(dat[rs].rmax, dat[rs].sum + dat[ls].rmax);
}

void build(int a, int b, int k, int l, int r)
{
    if (l + 1 == r) {
        dat[k].smax = arr[k - n + 1];
        dat[k].sum = arr[k - n + 1];
        dat[k].lmax = arr[k - n + 1];
        dat[k].rmax = arr[k - n + 1];
        return;
    }
    build(a, b, ls, l, (l + r) / 2);
    build(a, b, rs, (l + r) / 2, r);
    pushup(k);
}

void update(int k, int x)
{
    k += n - 1;
    dat[k].smax = x;
    dat[k].sum = x;
    dat[k].lmax = x;
    dat[k].rmax = x;
    while (k > 0) {
        k = (k - 1) / 2;
        pushup(k);
    }
}

node query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return node();
    if (a <= l && r <= b) return dat[k];
    node vl = query(a, b, ls, l, (l + r) / 2);
    node vr = query(a, b, rs, (l + r) / 2, r);
    node res;
    res.smax = max(max(vl.smax, vr.smax), vl.rmax + vr.lmax);
    res.sum = vl.sum + vr.sum;
    res.lmax = max(vl.lmax, vl.sum + vr.lmax);
    res.rmax = max(vr.rmax, vr.sum + vl.rmax);
    return res;
}

int main()
{
    int m;
    scanf("%d", &m);
    init(m);
    for (int i = 0; i < m; i++)
        scanf("%d", arr + i);
    for (int i = m; i < n; i++)
        arr[i] = -inf;
    build(0, n, 0, 0, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if (c == 0)
            update(a - 1, b);
        else
            printf("%d\n", query(a - 1, b, 0, 0, n).smax);
    }
    return 0;
}