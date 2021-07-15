#define ls (k * 2 + 1)
#define rs (k * 2 + 2)
typedef long long ll;

ll dat[4 * MAXN], lazy[4 * MAXN];
ll n;  // size of array, not of the tree

void init(ll m)
{
    n = 1;
    while (n < m) n *= 2;
}

void pushup(ll k)
{
    dat[k] = dat[ls] + dat[rs];
}

void pushdown(ll k)
{
    if (k < n - 1) {
        lazy[ls] += lazy[k];
        lazy[rs] += lazy[k];
    }
    lazy[k] = 0;
}

void build(ll a, ll b, ll k, ll l, ll r)
{
    if (l + 1 == r) {
        dat[k] = arr[k - n + 1];
        return;
    }
    build(a, b, ls, l, (l + r) / 2);
    build(a, b, rs, (l + r) / 2, r);
    pushup(k);
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

void update(ll a, ll b, ll x, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        lazy[k] += x;
        return;
    }
    dat[k] += (min(b, r) - max(a, l)) * x;
    update(a, b, x, ls, l, (l + r) / 2);
    update(a, b, x, rs, (l + r) / 2, r);
}

ll query(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l) return 0;
    if (lazy[k]) {
        dat[k] += (r - l) * lazy[k];
        pushdown(k);
    }
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, ls, l, (l + r) / 2);
    ll vr = query(a, b, rs, (l + r) / 2, r);
    return vl + vr;
}

//  init(m);	// init() will calculate n from m

//  //read leaf data
//  ll *array = dat + n - 1;
//  for (ll i = 0; i < m; i++) {
//      scanf("%lld", array + i);
//  }

//  // build tree
//  for (ll i = n - 2; i >= 0; i--)
//      dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];

//  // query [l, r)
//  query(l, r, 0, 0, n)

//  // update each elements of [l, r) to a
//  update(l, r, a, 0, 0, n)


// maximum subtotal

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
    // main idea
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