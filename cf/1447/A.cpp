#include <iostream>
#include <iomanip>
using namespace std;

#define INF 2e9

typedef long long ll;

void solve()
{
	int N;
	cin >> N;
	cout << N << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
