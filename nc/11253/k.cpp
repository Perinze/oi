#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, k;
int b[maxn];
int s[maxn], tp;
vector<int> G[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0, p, x; i < k; i++) {
		cin >> p >> x;
		b[p] = x;
	}
	tp = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			if (tp + 1 > b[i]) {
				G[i].push_back(s[tp]);
				clog << i << " -> " << s[tp] << endl;
			}
			while (i < s[tp]) {
				G[s[tp]].push_back(i);
				clog << s[tp] << " -> " << i << endl;
				tp--;
			} 
		} else {
			if (tp) {
				G[s[tp]].push_back(i);
				clog << s[tp] << " -> " << i << endl;
			}
			s[++tp] = i;
		}
	}
	return 0;
}