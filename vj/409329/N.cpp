#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void solve(int t)
{
	int x;
	string who;
	cin >> x >> who;
	string winner;
	if (who == "Alice")	// take the last to lose
	// just leave 3 * n to yourself
	// who face 3 * n will win
	// 3 * n + 1 will lose
	// 1 will lose
	// 2 will win
	// 3 * n + 2 i will take one to leave 3 * n + 1 to the opposite
	// he will lose
	// i will win
	{
		if (x % 3 == 0)	// then Bob take the last
			winner = "Alice";
		else if (x % 3 == 2)
			winner = "Alice";
		else
			winner = "Bob";
	}
	else	// take the last to win
	// who face 3 * n will lose
	// 3 * n + 1 or 3 * n + 2 will win
	// Bob start first
	{
		if (x % 3 == 0)	// then Alice take the last
			winner = "Alice";
		else
			winner = "Bob";
	}
	cout << "Case " << t << ": " << winner << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
