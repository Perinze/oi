#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

ll f(ll x)
{
    return x * (x - 1) / 2;
}

const int maxn = 100010;
typedef pair<int, int> P;
int n;
P a[maxn];

ll solve(int l, int r)
{
    ll res = 0;
    for (int i = 1; i < r - l; i++) {
        res += (a[l + i].second - a[l + i - 1].second) * f(i);
        res += (a[r - i].second - a[r - i - 1].second) * f(i);
    }
    res += f(r - l) * (n - a[r - 1].second + a[l].second - 1 + 1);
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            a[i] = P(x, i);
        }
        sort(a + 1, a + 1 + n);
        vector<int> start;
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].first != tmp) {
                start.push_back(i);
                tmp = a[i].first;
            }
        }
        ll ans = 0;
        for (int i = 0; i + 1 < start.size(); i++) {
            ans += solve(start[i], start[i + 1]);
        }
        ans += solve(start.back(), n + 1);
        printf("%lld\n", ans);
    }
    return 0;
}