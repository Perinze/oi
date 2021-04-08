#include <cstdio>
#include <cstring>
#include <cctype>

typedef long long ll;

namespace io {
    const ll MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s= 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') s = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        return x * s;
    }
}

ll cnt[100010];
ll n, q;
ll a[100010];
ll sum;

int main()
{
    for (ll i = 0; i < 100010; i++)
        cnt[i] = -1 - i * 2;
    ll T = io::read<ll>();
    for (ll cas = 1; cas <= T; cas++) {
        sum = 0;
        n = io::read<ll>();
        q = io::read<ll>();
        for (ll i = 0; i < n; i++) {
            a[i] = io::read<ll>();
            sum += a[i] * (cnt[i] + n);
        }
        printf("Case %lld:\n", cas);
        while (q--) {
            ll cmd = io::read<ll>();
            if (cmd == 0) {
                ll x  = io::read<ll>();
                ll v = io::read<ll>();
                sum += (v - a[x]) * (cnt[x] + n);
                a[x] = v;
            } else {
                printf("%lld\n", sum);
            }
        }
    }
    return 0;
}