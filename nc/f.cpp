#include <cstdio>
#include <climits>
#include <vector>
#include <list>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
int n;

void reduce(list<P> &v)
{
    ll mi = 1e18 + 10;
    for (auto ite = v.begin(); ite != v.end(); ite++)
        mi = min(mi, ite->first);
    if (mi > n)
        for (auto ite = v.begin(); ite != v.end(); ite++)
            ite->first -= mi - n;
}

int main()
{
    scanf("%d", &n);
    //vector<P> vec;
    list<P> vec;
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        vec.push_back(P(x, i));
    }
    reduce(vec);
    auto ite = vec.begin();
    ll d = 1;
    while (!vec.empty()) {
        ite->first -= d;
        if (ite->first <= 0) {
            printf("%lld ", ite->second);
            list<P>::iterator nite = ite;
            nite++;
            vec.erase(ite);
            ite = nite;
            reduce(vec);
        } else {
            ite++;
            d++;
        }
        if (ite == vec.end()) {
            ite = vec.begin();
            d = 1;
        }
    }
    puts("");
    return 0;
}