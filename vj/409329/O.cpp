#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

#define INF 2e9

typedef long long ll;

void solve(int tt)
{
	ll n, d;
	cin >> n >> d;
	ll ans = d;
	int t = 1;
	while (ans % n)
	{
		ans = ans * 10 + d;
		ans %= n;
		t++;
	}
	cout << "Case " << tt << ": " << t << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
