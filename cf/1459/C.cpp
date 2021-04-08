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
ll a[200000], b[200000];

ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	if (!b) return a;
	return gcd(b, a % b);
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	if (n == 1)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[0] + b[j] << ' ';
		}
		return;
	}

	sort(a, a + n);
	ll mina = a[0];
	ll gcda = a[1] - mina;
	for (int i = 1; i < n; i++)
	{
		gcda = gcd(gcda, a[i] - mina);
	}
	//cout << "gcda = " << gcda << endl;

	for (int j = 0; j < m; j++)
	{
		ll ans = gcd(gcda, b[j] + mina);
		cout << ans << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
