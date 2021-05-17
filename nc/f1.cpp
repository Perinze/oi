#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
ll n;
vector<P> vec;

int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        vec.push_back(P(x, i + 1));
    }
    while (!vec.empty()) {
        ll minv = 1e18 + 10, minp = 0;
        for (ll i = 0; i < vec.size(); i++) {
            ll d = vec[i].first - i;
            if (d < minv) {
                minv = d;
                minp = i;
            }
        }
        printf("%lld ", vec[minp].second);
        vec.erase(vec.begin() + minp);
    }
    puts("");
    return 0;
}