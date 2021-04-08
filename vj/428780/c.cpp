#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define MAXN 60
typedef long long ll;
int n;
ll w[MAXN];
ll bs;
ll ans = LLONG_MAX;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", w + i);
        if (i) bs += w[i] * w[i - 1];
    }
    bs += w[0] * w[n - 1];
    ll res;
    for (int i = 0; i < n; i++) {
        res = bs;
        for (int j = 0; j < n - 2; j++) {
            int k = (j + i + 2) % n;
            res += w[i] * w[k] * 2;
        }
    }
}