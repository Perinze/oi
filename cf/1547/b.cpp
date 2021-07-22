#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	char tmp[30];
	int T;
	cin >> T;
	while (T--) {
		cin >> tmp;
		int l = 0, r = strlen(tmp) - 1;
		char mx = max(tmp[l], tmp[r]);
		while (l <= r) {
			if (tmp[l] == mx) l++;
			else if (tmp[r] == mx) r--;
			else break;
			mx--;
		}
		if (l <= r || mx != 'a' - 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}