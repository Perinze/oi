#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;
	k--;

	vector<int> ss;
	int ks;
	for (int i = 0; i < n; i++)
	{
		int s; cin >> s;
		if (i == k)
			ks = s;
		if (s > 0)
			ss.push_back(s);
	}
	
	int ans = 0;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] >= ks)
			ans++;
	}

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
