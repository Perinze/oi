#include <iostream>
#include <cmath>
using namespace std;

const double log_2 = log(2);

typedef long long ll;

ll getl(ll x)
{
	return (ll)sqrt(x - 1);
}

void solve(int t)
{
	ll S;
	cin >> S;

	ll lvl = getl(S);
	ll j = S - 1;
	ll mid = (lvl * lvl + (lvl + 1) * (lvl + 1) - 1) / 2;
	ll x, y;
	if (j < mid)
	{
		x = lvl, y = j - lvl * lvl;
	}
	else
	{
		y = lvl, x = (lvl + 1) * (lvl + 1) - 1 - j;
	}
	if (lvl & 1)
	{
		swap(x, y);
	}
	
	cout << "Case " << t << ": " << x + 1 << ' ' << y + 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
	return 0;
}
