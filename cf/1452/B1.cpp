#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
int n;
ll a[100000];
ll sum;

bool check(int m, int sum)
{
	if ((sum - m * (n - 1)) % (n - 1) == 0) return true;
	return false;
}

void solve()
{
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);
	
	int d = 0;
	while (!(check(a[n - 1], sum) && check(a[n - 2], sum)))
	{
		a[0]++;
		sum++;
		d++;
		sort(a, a + n);
	}

	cout << d << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
