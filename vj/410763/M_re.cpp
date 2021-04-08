#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

int dfs(int x, int rest)
{
	if (rest == 1) return 1;
	int res = 0;
	for (int i = x; i <= rest; i++)
	{
		if (rest % i == 0)
			res += dfs(i, rest / i);
	}
	return res;
}

void solve()
{
	int x;
	cin >> x;
	cout << dfs(2, x) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
