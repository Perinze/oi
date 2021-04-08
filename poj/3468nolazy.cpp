#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 101000;
ll dat[4 * MAXN];
int n;  // size of array, not of the tree

char gch()
{
    char c;
    while ((c = getchar()) != EOF) {
        if (c == 'Q' || c == 'C')
            return c;
    }
}

void init(int m)
{
    n = 1;
    while (n < m) n *= 2;
}

void add(int a, int b, ll x, int k, int l, int r)
{
    if (b <= l || r <= a) return;
    dat[k] += (min(b, r) - max(a, l)) * x;
    if (k < n - 1) {
        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    }
}

ll query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
}

int main()
{
    int m, q;
    scanf("%d%d", &m, &q);
    init(m);
    ll *array = dat + n - 1;
    for (ll i = 0; i < m; i++) {
        scanf("%lld", array + i);
    }
    for (int i = n - 2; i >= 0; i--)
        dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
    while (q--) {
        /*
        int ret = 0;
        for (ll i = 0; i < 2 * n - 1; i++) {
            cout << dat[i] << ' ';
            if (i == ret) {
                cout << endl;
                ret = (ret + 1) * 2;
            }
        }
        cout << endl;
        */
        char c;
        int l, r;
        c = gch();
        scanf("%d%d", &l, &r);
        l--;
        if (c == 'Q')
            cout << query(l, r, 0, 0, n) << endl;
        else {
            ll a;
            scanf("%lld", &a);
            add(l, r, a, 0, 0, n);
        }
    }
    return 0;
}