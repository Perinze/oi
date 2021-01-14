#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = (ll)(35 * 10e15 + 1);

int solve()
{
	ll n;
	ll a[35];
	cin >> n;
	if (n == 0) return 1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	pair<ll, ll> ps[1 << (35 / 2)];
	cout << "ps point to " << ps << endl;
	ps[0] = make_pair(INF, INF);
	ll n2 = n / 2;
	for (ll i = 1; i < 1 << n2; i++)
	{
		cout << "S1=" << i << ", ";
		ll subsum = 0;
		ll subnum = 0;
		for (ll j = 0; j < n2; j++)
		{
			if (i >> j & 1)
			{
				subnum++;
				subsum += a[j];
			}
		}
		cout << subsum << ", " << subnum << endl;
		ps[i] = make_pair(subsum, subnum);
	}

	sort(ps, ps + (1 << n2));
	for (ll i = 0; i < 1 << n2; i++)
		cout << ps[i].first << "," << ps[i].second << endl;
	cout << endl;

	ll res = INF;
	ll resnum = 36;
	for (ll i = 0; i < 1 << (n - n2); i++)
	{
		cout << "S2=" << i << ", ";
		ll subsum = 0;
		ll subnum = 0;
		for (ll j = 0; j < n - n2; j++)
		{
			if (i >> j & 1)
			{
				subnum++;
				subsum += a[j];
			}
		}
		cout << subsum << ", " << subnum << endl;

		cout << "tar point to " << lower_bound(ps, ps + (1 << n2), make_pair(-subsum, INF)) - 1 << endl;
		pair<ll, ll> tar = *(lower_bound(ps, ps + (1 << n2), make_pair(-subsum, INF)));
		cout << "get s1 " << tar.first << "," << tar.second << endl;

		if (tar.first + subsum < res || (tar.first + subsum == res && tar.second + subnum < resnum))
		{
			cout << "set min res" << endl;
			res = tar.first + subsum;
			resnum = tar.second + subnum;
		}
	}
	
	cout << res << ' ' << resnum << endl;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	while (solve() != 1);
	return 0;
}
