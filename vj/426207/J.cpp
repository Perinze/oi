#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
ll tot = 1000000;
set<ll> s;
vector<ll> ans;
ll sum = 0;
ll n;

int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        s.insert(x);
        sum += x - 1;
    }
    for (ll y = tot - sum; sum && y <= tot; y = max(y + 1, tot - sum)) {
        if (!s.count(y)) {
            ans.push_back(y);
            sum -= y;
        }
    }
    ans.push_back(tot);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%lld ", ans[i]);
    putchar('\n');
    return 0;
}