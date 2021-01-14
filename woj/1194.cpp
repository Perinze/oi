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
	int n;
	while (cin >> n)
	{
		if (n % 2 == 1) cout << 0 << endl;
		else if (n % 4 == 0) cout << 2 << endl;
		else cout << 1 << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
