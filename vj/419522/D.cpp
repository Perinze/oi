#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
P m[1000000];
int x[1000], y[1000];

ll fac(int n)
{
    if (n <= 1) return 1;
    return fac(n - 1) * n;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int n;
        scanf("%d", &n);
        memset(x, 0, sizeof(int) * n);
        memset(y, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", x + i, y + i);
        int s = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                m[s++] = P(x[i] + x[j], y[i] + y[j]);
        sort(m, m + s);
        ll ans = 0;
        P crt, lst = m[0];
        int num = 1;
        for (int i = 1; i < s; i++)
        {
            crt = m[i];
            if (crt != lst)
            {
                ans += num * (num - 1) / 2;
                num = 0;
            }
            num++;
            lst = crt;
        }
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}