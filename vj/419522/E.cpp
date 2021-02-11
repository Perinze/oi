#include <iostream>
using namespace std;

typedef long long ll;

ll fac[1000001];
void init(ll mod)
{
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fac[i] = fac[i - 1] * i % mod;
}

ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll C(ll n, ll m, ll mod)
{
    if (m > n) return 0;
    return fac[n] * mod_pow(fac[m] * fac[n - m] % mod, mod - 2, mod) % mod;
}

ll lucas(ll n, ll m, ll mod)
{
    if (m == 0) return 1;
    return C(n % mod, m % mod, mod) * lucas(n / mod, m / mod, mod) % mod;
}

int main()
{
    init(1000003);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ll n, k;
        cin >> n >> k;
        cout << "Case " << t << ": ";
        cout << lucas(n, k, 1000003) << endl;
    }
    return 0;
}