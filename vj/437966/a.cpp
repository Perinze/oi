#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxa = 1e7 + 10;
const ll maxn = 1e7 + 10;

// linear sieve and euler
bool is_prime[maxa]; // 0 - prime, 1 - not prime
ll prime[maxn];
ll phi[maxn];
ll phipre[maxn];
ll fact[maxn];
ll cnt;
ll n, m, p;
//vector<ll> factor;

ll pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

void euler(ll n)
{
	is_prime[0] = is_prime[1] = 1;
	phi[1] = 1;
	for (ll i = 2; i < n; i++) {
		if (is_prime[i] == 0) {
			prime[cnt++] = i;
			phi[i] = i - 1;
            fact[i] = i;
		}
		for (ll j = 0; j < cnt && i * prime[j] < n; j++) {
			is_prime[i * prime[j]] = 1;
            fact[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				// absolutely not necessary to use phi[i * prime[j]] = phi[i] * prime[j] which is hard to understand
				// but maybe a little little bit faster, and it is just correct
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
    for (ll i = 1; i < n; i++) {
        phipre[i] = phi[i];
        phipre[i] += phipre[i - 1];
        phipre[i] %= mod;
    }
}

ll sum(ll n, ll m)
{
    if (n == 1) return phipre[m];
    if (m == 1) return phi[n];
    if (m == 0) return 0;
    return ((fact[n] - 1) * sum(n / fact[n], m) % mod + sum(n, m / fact[n]) % mod) % mod;
}

ll powk(ll k, ll p)
{
    if (p == 1) return 0;
    ll t = powk(k, phi[p]);
    ll res = pow(k, t + phi[p], p);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    euler(maxn);
    while (cin >> n >> m >> p) {
        ll k = sum(n, m);
        //cout << k << " : ";
        cout << powk(k, p) << endl;
    }
    return 0;
}