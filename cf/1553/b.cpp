#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (int)l; i < (int)r; i++)
using namespace std;
using ll = long long;

int main() {
	int T;
	cin >> T;
	char s[505], t[505];
	while (T--) {
		cin >> s >> t;
		int ls = strlen(s), lt = strlen(t);
		rep(i, 0, ls) {
			if (s[i] == t[0]) {
				int p = i + 1;
				int j = 1;
				while (j < lt && s[p] == t[j]) {
					p++, j++;
				}
				if (j == lt) {
					cout << "YES" << endl;
					break;
				}
				p -= 2;
				while (j < lt && s[p] == t[j]) {
					p--, j++;
				}
				if (j == lt) {
					cout << "YES" << endl;
					break;
				}
			}
			if (i == ls - 1) {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
