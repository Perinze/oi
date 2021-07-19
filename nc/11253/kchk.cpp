#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], b[maxn];
int p[maxn], x[maxn];
int n, k;

void getb()
{
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && s.top() > a[i]) s.pop();
		s.push(a[i]);
		b[i] = s.size();
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> p[i] >> x[i];
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	do {
		getb();
		bool fail = false;
		for (int i = 1; i <= k; i++) {
			if (b[p[i]] != x[i]) {
				fail = true;
				break;
			}
		}
		if (fail) continue;
		for (int i = 1; i <= n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
		return 0;
	} while (next_permutation(a + 1, a + 1 + n));
	return 0;
}