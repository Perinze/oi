#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

void solve(int t)
{
	
	ll w;
	cin >> w;

	cout << "Case " << t << ": ";
	if (w % 2) cout << "Impossible";
	else
	{
		for (ll i = 2; i < w; i *= 2)
		{
			if (w / i % 2)
			{
				cout << w / i << ' ' << i;
				break;
			}
		}
	}

	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
