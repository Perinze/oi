#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

int N, a, b;
string s;
int dp[100000];

void solve()
{
	cin >> a >> b;
	cin >> s;
	N = s.size();
	
	int noz = 0;
	if (s[0] == '0')
	{
		noz = 1;
		dp[0] = 0;
	}
	else
	{
		dp[0] = a;
	}

	char last = s[0];
	for (int i = 1; i < N; i++)
	{
		if (last == '0' && s[i] == '1')
		{
			if (i - noz - 1 >= 0)
				dp[i] = min(dp[i - 1] + a, dp[i - noz - 1] + b * noz);
			else
				dp[i] = dp[i - 1] + a;
			last = s[i];
			continue;
		}

		if (last == '1' && s[i] == '0')
		{
			noz = 1;
		}
		else if (last == '0' && s[i] == '0')
		{
			noz++;
		}
		dp[i] = dp[i - 1];
		last = s[i];
	}

	//for (int i = 0; i < N; i++) cout << dp[i] << ' ';
	//cout << endl;
	cout << dp[N - 1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
