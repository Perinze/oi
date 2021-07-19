#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, k;
int p[maxn], x[maxn];

int a[maxn];

void exchange(int l, int r)
{
	int tmp = a[l];
	for (int i = l; i < r; i++)
		a[i] = a[i + 1];
	a[r] = tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> p[i] >> x[i];
	}
	for (int i = 1; i <= n; i++)
		a[i] = i;
	bool upd;
	do {
		upd = false;
		for (int i = k; i > 0; i--) {
			int r = p[i];
			int l = x[i];
			if (l != r) {
				exchange(l, r);
				upd = true;
			}
		}
	} while (upd);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}