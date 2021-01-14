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

void solve()
{
	string s;
	cin >> s;

	int dp[s.size() + 1];
	dp[0] = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'X') dp[i + 1] = 0;
		else dp[i + 1] = dp[i] + 1;
	}

	int ans = 0;
	for (int i = 1; i <= s.size(); i++)
	{
		ans += dp[i];
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
