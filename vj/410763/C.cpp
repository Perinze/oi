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

void solve()
{
	int n;
	int a;
	int map[101];	// represent the number of times a value appears
	memset(map, 0, sizeof(map));
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		map[a]++;
		ans = max(ans, map[a]);
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
