#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int dp[100000];

void solve()
{
	int a, b;
	string s;
	cin >> a >> b >> s;

	int nz = 0;	// num of zero
	if (s[0] == '1') dp[0] = a;	// activate #0
	else dp[0] = 0;
	char last = s[0];	// last building
	int i;
	for (i = 1; i < s.length(); i++)
	{
		if (last == '0' && s[i] == '1')
		{
			if (nz == 0)	// first meet 1
				dp[i] = dp[i-1] + a;
			else
				dp[i] = min(dp[i-nz-1] + nz * b, dp[i-1] + a);
		}
		else
		{
			dp[i] = dp[i-1];
		}

		if (last == '1' && s[i] == '0')
		{
			nz = 1;
		}
		else if (last == '0' && s[i] == '0')
		{
			if (nz != 0)	// except the first 0s
				nz++;
		}
		
		last = s[i];
	}
	//for (i = 0; i < s.length(); i++)
	//	cout << dp[i];
	//cout << endl;
	cout << dp[i-1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
