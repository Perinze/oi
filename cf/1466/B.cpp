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
bool used[200010];

void solve()
{
	int n;
	cin >> n;
	memset(used, 0, sizeof(used));

	int crt;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> crt;
		if (!used[crt])
		{
			used[crt] = true;
			ans++;
			continue;
		}
		if (!used[crt + 1])
		{
			used[crt + 1] = true;
			ans++;
			continue;
		}
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
