#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define INF 2e9

typedef long long ll;
bool win[3];

void roll()
{
	win[0] = win[1];
	win[1] = win[2];
}

void solve(int t)
{
	int n;
	string who;
	cin >> n >> who;

	if (who == "Alice")
	{
		win[0] = true;
	}
	else
	{
		win[0] = false;
	}

	win[1] = !win[0];
	for (int j = 2; j <= n; j++)
	{
		win[2] = false;
		win[2] |= !win[1];
		win[2] |= !win[0];
		roll();
	}

	if (who == "Alice")
	{
		if (win[n]) cout << "Case " << t << ": Alice" << endl;
		else cout << "Case " << t << ": Bob" << endl;
	}
	else
	{
		if (win[n]) cout << "Case " << t << ": Bob" << endl;
		else cout << "Case " << t << ": Alice" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
