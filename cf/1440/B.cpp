#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
int n, k;
int m;
int a[1000000];

void solve()
{
	cin >> n >> k;
	//int m = (n + 1) / 2 - 1;
	for (int i = 0; i < n * k; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n * k);
	ll res = 0;
	int i = n * k - 1 - n / 2;
	for (int j = 0; j < k; j++)
	{
		//cout << a[i] << ' ';
		res += a[i];
		i -= n / 2 + 1;
	}
	//cout << endl;
	cout << res << endl;;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
