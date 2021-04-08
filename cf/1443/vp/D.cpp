#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
int N;
int a[30000];

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	int dec = a[0], inc = 0, linc = 0;
	for (int i = 1; i < N; i++)
	{
		// last dec -> now dec
		dec = a[i] - inc;
		inc = a[i] - dec;
		if (inc < linc)
		{
			cout << "NO" << endl;
			return;
		}
		linc = inc;
	}
	cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
