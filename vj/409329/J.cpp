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
const int INF = 1000000;

void solve()
{
	int n, k;
	cin >> n >> k;
	int dp[100001];
	fill(dp, dp + k + 1, INF);

	for (int i = n + 1; i <= k; i++)
	{
		if (i & 1)
		{
			
		}
		else 
		{

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
