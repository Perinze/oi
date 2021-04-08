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
	int x, y;
	cin >> x >> y;
	if (x == y) cout << 2 * x << endl;
	else cout << 2 * max(x, y) - 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
