#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 500010;
const int mod = 1000000007;

int A[maxn];
int seq[maxn];
int num[maxn];
int bit[maxn], n, m;

int sum(int i_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		s = (s + bit[i]) % mod;
	return s;
}

void add(int i_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		bit[i] = (bit[i] + x) % mod;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        memset(bit, 0, sizeof(bit));
        ll x, y, z;
        scanf("%d%d%lld%lld%lld", &n, &m, &x, &y, &z);
        for (int i = 0; i < m; i++)
            scanf("%d", A + i);
        for (int i = 0; i < n; i++) {
            seq[i] = num[i] = A[i % m];
            A[i % m] = (x * A[i % m] + y * (i + 1)) % z;
        }
        for (int i = 0; i < n; i++) printf(" %d", seq[i]);
        putchar('\n');
        ll ans = 0;
        sort(num, num + n);
        int cnt = unique(num, num + n) - num; // cnt is the number of unique numbers
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(num, num + cnt, seq[i]) - num;
            ll x = sum(pos) + 1;
            ans = (x + ans) % mod;
            add(pos + 1, x);
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}