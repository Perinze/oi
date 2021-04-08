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
	cin >> n;
	
	int m = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m = max(m, a);
		s += a;
	}
	
	int d = 0;
	if (m * (n - 1) - s < 0)
	{
		d += s - m * (n - 1);	// m += d
		s += d;
	}
	if (s % (n - 1) != 0) d += n - 1 - s % (n - 1);
	cout << d << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
