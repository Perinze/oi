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

int k[][10] = {
	{1},
	{1, 1},
	{1, 2, 1},
	{1, 3, 3, 1},
	{1, 4, 6, 4, 1},
	{1, 5, 10, 10, 5, 1},
	{1, 6, 15, 20, 15, 6, 1},
	{1, 7, 21, 35, 35, 21, 7, 1},
	{1, 8, 28, 56, 70, 56, 28, 8, 1},
	{1, 9, 36, 84, 126, 126, 84, 36, 9, 1}
	//{1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}
};

void solve()
{
	int N, sum;
	cin >> N >> sum;
	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		ans.push_back(i);
	}
	
	do {
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			res += k[N - 1][i] * ans[i];
		}
		if (res == sum)
		{
			for (int i = 0; i < N; i++)
			{
				cout << ans[i] << ' ';
			}
			cout << endl;
			return;
		}
	} while (next_permutation(ans.begin(), ans.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
