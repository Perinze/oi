#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

void print_bin(int x)
{
	if (!x) cout << 0 << endl;
	int i = 0;
	while (1 << i < x) i++;
	while (i--)
	{
		cout << (x >> i & 1);
	}
}

void select(int n, int comb)
{
	for (int i = 0; i < n; i++)
	{
		if (comb >> i & 1) cout << i << ' ';
	}
	cout << endl;
}

void solve()
{
	int n, k;
	cin >> n >> k;

	int comb = (1 << k) - 1;
	while (comb < 1 << n) {
		print_bin(comb);
		cout << endl;
		select(n, comb);
		int x = comb & -comb, y = comb + x;
		comb = ((comb & ~y) / x >> 1) | y;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
