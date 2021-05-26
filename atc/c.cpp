#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 100010;
int a[maxn], b[maxn], c[maxn], bc[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    map<int, int> sbc;
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        sbc[b[c[i]]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sbc[a[i]];
    }
    printf("%lld\n", ans);

    return 0;
}