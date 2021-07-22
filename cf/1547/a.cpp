#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int x[3], y[3];
	while (T--) {
		for (int i = 0; i < 3; i++)
			cin >> x[i] >> y[i];
		ll res = abs(x[1] - x[0]) + abs(y[1] - y[0]);
		if (x[1] == x[0] && x[1] == x[2] && (y[2] - y[0]) * (y[2] - y[1]) < 0)
			res += 2;
		if (y[1] == y[0] && y[1] == y[2] && (x[2] - x[0]) * (x[2] - x[1]) < 0)
			res += 2;
		cout << res << endl;
	}
	return 0;
}