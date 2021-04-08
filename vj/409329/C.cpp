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
	int n;
	while (cin >> n)
	{
		cout << 1 + 3 * ((1 << (n - 1)) - 1) << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
