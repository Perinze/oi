#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

void solve()
{
	int n, c0, c1, h;
	string str;
	cin >> n >> c0 >> c1 >> h;
	cin >> str;

	int v[2];
	v[0] = min(h + c1, c0);
	v[1] = min(h + c0, c1);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int ch = str[i] - '0';
		res += v[ch];
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
