#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
int N;
int a[200000];

bool check(int l, int r)
{
	//cout << l << ", " << r << endl;
	int sum = a[l] ^ a[r];
	//cout << sum << endl;
	for (int i = l + 1; i < r; i++)
	{
		//cout << "-= " << a[i] << endl;
		sum -= a[i];
	}
	//if (sum) cout << "NO" << endl;
	//else cout << "YES" << endl;

	if (sum) return false;
	else return true;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	int res = 0;
	for (int d = 2; d < N; d++)
	{
		for (int i = 0; i <= N - d; i++)
		{
			if (check(i, i + d)) res++;
		}
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
