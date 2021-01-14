#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	int n; ll z;
	cin >> n >> z;
	vector<ll> li;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		bool skip = false;
		for (int j = 0; j < li.size(); j++)
		{
			if ((li[j] + a) % z == 0)
			{
				li[j] = min(li[j], a);
				skip = true;
				for (int k = li.size() - 1; k > j; k--)
				{
					if (li[k] == li[j])
					{
						li.erase(li.begin() + k);
					}
				}
			}
		}
		if (!skip)
		{
			li.push_back(a);
			/*
			for (int i = 0; i < li.size(); i++)
				cout << li[i] << ' ';
			cout << endl;
			*/
		}
	}

	ll res = 0;
	for (int i = 0; i < li.size(); i++)
	{
		res += li[i] * li[i];
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
