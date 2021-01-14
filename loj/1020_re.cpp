#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void solve(int t)
{
	int n;
	string who;
	cin >> n >> who;

	cout << "Case " << t << ": ";
	if (n == 1) cout << "Bob";
	else if (n == 2) cout << who;
	else
	{
		if (who == "Alice") cout << "Bob";
		else cout << "Alice";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
