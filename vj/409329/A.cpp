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
	ll n, m, a;
	cin >> n >> m >> a;
	cout << ((n - 1) / a + 1) * ((m - 1) / a + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
