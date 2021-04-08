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

void solve()
{
	int n, k;
	double a[5001];
	cin >> n >> k;

	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		double v; cin >> v;
		a[i] = a[i - 1] + v;
	}
	/*
	for (int i = 0; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	*/

	double avg = 0.0;
	for (; k <= n; k++)
	{
		//cout << "k = " << k << endl;
		for (int i = 0; i <= n - k; i++)
		{
			double s = a[i + k] - a[i];
			//cout << "seg(" << i << ", " << i + k - 1 << ") = " << s << endl;
			//cout << "current avg = " << s / (double)k << endl;
			avg = max(avg, s / (double)k);
		}
		//cout << endl;
	}
	cout << fixed << setprecision(12);
	cout << avg << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
