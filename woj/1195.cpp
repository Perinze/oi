#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define INF 2e9

typedef long long ll;

ll zmy(ll n)
{
	return (n * n + n) / 2;
}

void solve()
{
	ll n;
	cin >> n;
	if (n == 0) cout << 0 << endl;
	else if (n == 1) cout << 0 << endl;
	else if (n == 2) cout << 1 << endl;
	else if (n == 3) cout << 2 << endl;
	else if (n == 4) cout << 3 << endl;
	else
	{
		if ((n + 8) % 3 == 0)
		{
			ll k = (n + 8) / 3 - 3;
			cout << 3 * zmy(k) << endl;
		}
		else
		{
			cout << zmy(n - 3) + 2 << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
