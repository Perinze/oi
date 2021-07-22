#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
	if (a > b) swap(a, b);
	if (a == 2 && b == 8) return 1;
	if (a == b) return 2;
	return 3;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		int s1 = solve(a1, b1);
		int s2 = solve(a2, b2);
		if (min(s1, s2) == 1) {
			if (s1 == s2) cout << "tie";
			else cout << (s1 < s2 ? "first" : "second");
		} else if (min(s1, s2) == 2 && s1 != s2) {
			cout << (s1 < s2 ? "first" : "second");
		} else if (min(s1, s2) == 2) {
			cout << (a1 > a2 ? "first" : "second");
		} else {
			int c1 = (a1 + b1) % 10;
			int c2 = (a2 + b2) % 20;
			if (c1 == c2) {
				if (b1 == b2) cout << "tie";
				else cout << (b1 > b2 ? "first" : "second");
			} else {
				cout << (c1 > c2 ? "first" : "second");
			}
		}
		cout << endl;
	}
	return 0;
}