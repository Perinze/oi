#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	cin >> x >> y;
	if (x > y) swap(x, y);
	int c, d;
	for (int i = 1; i <= a; i++) {
		for (int j = 0; i * j <= b; j++) {
			cout << i << ", " << i * j << " => ";
			c = a - i, d = b - i * j;
			if (c > d) swap(c, d);
			cout << c << ", " << d << endl;
			if (c == x && d == y) cout << "found" << endl;
			//s.insert(make_pair(a - i, b - i * j));
		}
	}
	for (int i = 1; i <= b; i++) {
		for (int j = 0; i * j <= a; j++) {
			cout << i * j << ", " << i << " => ";
			c = a - i * j, d = b - i;
			if (c > d) swap(c, d);
			cout << c << ", " << d << endl;
			if (c == x && d == y) cout << "found" << endl;
			//s.insert(make_pair(a - i * j, b - i));
		}
	}
	return 0;
}