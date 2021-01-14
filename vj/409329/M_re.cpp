#include <iostream>
using namespace std;

void solve(int t)
{
	int m, n;
	cin >> m >> n;

	int ans;
	if (min(m, n) == 1) ans = max(m, n);
	else if (min(m, n) == 2)
	{
		int l = max(m, n);
		l -= 2;
		if (l % 4 == 3)
		{
			ans = l / 4 * 4 + 6;
		}
		else
		{
			ans = l / 4 * 4 + 4;
		}
	}
	else ans = ((m + 1) / 2) * ((n + 1) / 2) + (m / 2) * (n / 2);
	cout << "Case " << t << ": " << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
