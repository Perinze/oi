#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1; y = 0;
    }
    return d;
}

int sign(ll x)
{
    if (x == 0) return 0;
    return x > 0? 1: -1;
}

ll ceil(ll x, ll y)
{
    int s = sign(x) * sign(y);
    return x / y + (x % y && s > 0);
}

ll floor(ll x, ll y)
{
    int s = sign(x) * sign(y);
    return x / y - (x % y && s < 0);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        ll a, b, c, x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
        printf("Case %d: ", cas);

        if (a == 0 && b == 0)
        {
            if (c == 0)
                printf("%lld\n", (x2 - x1 + 1) * (y2 - y1 + 1));
            else
                printf("0\n");
            continue;
        }
        else if (a == 0)
        {
            if (c % b != 0)
            {
                printf("0\n");
                continue;
            }
            int y0 = -c / b;
            if (y0 >= y1 && y0 <= y2) printf("%lld\n", x2 - x1 + 1);
            else printf("0\n");
            continue;
        }
        else if (b == 0)
        {
            if (c % a != 0)
            {
                printf("0\n");
                continue;
            }
            int x0 = -c / a;
            if (x0 >= x1 && x0 <= x2) printf("%lld\n", y2 - y1 + 1);
            else printf("0\n");
            continue;
        }

        ll x, y;
        ll gcd = extgcd(a, b, x, y);
        if (c % gcd)
        {
            printf("0\n");
            continue;
        }
        if (sign(gcd) * sign(b) < 0) swap(x1, x2);
        ll l1 = ceil(gcd * x1 + c * x, b);
        ll l2 = floor(gcd * x2 + c * x, b);
        if (sign(gcd) * sign(-a) < 0) swap(y1, y2);
        ll r1 = ceil(gcd * y1 + c * y, -a);
        ll r2 = floor(gcd * y2 + c * y, -a);
        ll l = max(l1, r1);
        ll r = min(l2, r2);
        if (l > r)
            printf("0\n");
        else 
            printf("%lld\n", r - l + 1);
    }
    return 0;
}