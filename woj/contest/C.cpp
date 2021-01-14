#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

int shift(int x, int s)
{
	if (s == 3)
	{
		if (x <= 9) return x * 111;
		else return x * 10101;
	}
	else if (s == 2)
	{
		if (x <= 9) return x * 11;
		else return x * 101;
	}
}

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << shift(a, 2) + shift(b, 3) + shift(c, 3) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
