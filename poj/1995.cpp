#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

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

void solve()
{
	ll mod;
	cin >> mod;
	ll res = 0;
	int H;
	cin >> H;
	while (H--)
	{
		ll a, b;
		cin >> a >> b;
		res += mod_pow(a, b, mod) % mod;
		res %= mod;
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
