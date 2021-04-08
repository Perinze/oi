#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

ll dp[36][36];

void solve()
{
	for (int i = 0; i < 36; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < 36; i++)
	{
		for (int j = i; j < 36; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	/*
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 36; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	for (int i = 1; i < 36; i++)
		cout << dp[i][i] << endl;
	*/
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	for (int i = 1; ; i++)
	{
		int N;
		cin >> N;
		if (N == -1) break;
		cout << i << ' ' << N << ' ' << 2 * dp[N][N] << endl;
	}
	return 0;
}
