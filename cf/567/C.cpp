#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n;
    int k;
    scanf("%d%d", &n, &k);
    long long ans = 0;
    map<int, long long> s1, s2;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % k == 0) {
            ans += s2[x / k];
            s2[x] += s1[x / k];
        }
        s1[x]++;
    }
    printf("%lld\n", ans);
    return 0;
}