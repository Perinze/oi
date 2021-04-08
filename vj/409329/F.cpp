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
	string ans = s;
	string cs = "?";
	for (int i = 1 ; i < s.size(); i++)
	{
		cs[0] = s.back(); s.pop_back();
		s.insert(0, cs);
		ans = min(ans, s);
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
