#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define INF 2e9

typedef long long ll;
int N;
int b[1000];

void solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	sort(b, b + N);
	int pre = b[0];
	for (int i = 1; i < N; i++)
	{
		if (b[i] == pre)
		{
			cout << "YES" << endl;
			return;
		}
		pre = b[i];
	}
	cout << "NO" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
