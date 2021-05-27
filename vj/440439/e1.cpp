#include <bits/stdc++.h>
using namespace std;

#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
typedef long long ll;
const int maxn = 1e5 + 10;
int n, p;
int a[maxn];
struct node {
    int l, r;
    ll sum, mul, add;
} tree[maxn * 4];

void pushup(int k)
{
    tree[k].sum = (tree[ls].sum + tree[rs].sum) % p;
}

void build(int k, int l, int r)
{
    if (l + 1 == r)
        tree[k] = {l, r, a[k - n + 1], 0, 1};
    else {
        tree[k] = {l, r, 0, 0, 1};
        build(ls, l, (l + r) / 2);
        build(rs, (l + r) / 2, r);
        pushup(k);
    }
}

void eval(int k, int mul, int add)
{
    tree[k].sum = (tree[k].sum * mul + (tree[k].r - tree[k].l) * add) % p;
    tree[k].mul = tree[k].mul * mul % p;
    tree[k].add = (tree[k].add * mul + add) % p;
}

void pushdown(int k)
{
    eval(ls, tree[k].mul, tree[k].add);
    eval(rs, tree[k].mul, tree[k].add);
    tree[k].mul = 1, tree[k].add = 0;
}

void modify(int k, int l, int r, int mul, int add)
{
    if (l <= tree[k].l && tree[k].r <= r)
        eval(k, mul, add);
    else {
        pushdown(k);
        int mid = (tree[k].l + tree[k].r) / 2;
        if (l <= mid) modify(ls, l, r, mul, add);
        if (mid < r) modify(rs, l, r, mul, add);
        pushup(k);
    }
}

int query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
        return tree[k].sum;
    pushdown(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    int sum = 0;
    if (l <= mid) sum = query(ls, l, r);
    if (mid < r) sum = (sum + query(rs, l, r)) % p;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int m;
    cin >> m >> p;
    n = 1;
    while (n < m) n *= 2;
    for (int i = 0; i < m; i++) cin >> a[i];
    build(0, 0, n);
    int q; cin >> q;
    while (q--) {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> x;
            modify(0, 0, n, x, 0);
        } else if (t == 2) {
            cin >> x;
            modify(0, 0, n, 1, x);
        } else
            cout << query(0, 0, n) << endl;
    }
    return 0;
}