#include <cstdio>
typedef long long ll;
const int maxn = 1e6 + 10;

ll bit[maxn], n;

ll pre[maxn];
void init(int n)
{
    for (int i = 1; i <= n; i++)
        bit[i] = pre[i] - pre[i - (i & -i)];
}

ll query(ll i_)
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

inline ll query(ll i, ll j)
{
	return query(j) - query(i - 1);
}

void add(ll i_, ll x)
{
	for (ll i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

int main()
{
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", pre + i);
        pre[i] += pre[i - 1];
    }
    init(n);
    for (int i = 0; i < q; i++) {
        int cmd; ll x, y;
        scanf("%d%lld%lld", &cmd, &x, &y);
        if (cmd == 1) {
            add(x, y);
        } else {
            printf("%lld\n", query(x, y));
        }
    }
    return 0;
}