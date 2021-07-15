#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
const int nnode = 26;

namespace ac {
	int trie[maxn][nnode];
	int fail[maxn];
	int end[maxn];
	int cnt;

	int newnode()
	{
		memset(trie[cnt], 0, sizeof(trie[cnt]));
		fail[cnt] = 0;
		end[cnt] = 0;
		return cnt++;
	}

	void init()
	{
		cnt = 0;
		newnode();
	}

	void insert(const char *buf)
	{
		int crt = 0;
		for (int i = 0; buf[i]; i++) {
			int x = buf[i] - 'a';
			if (!trie[crt][x])
				trie[crt][x] = newnode();
			crt = trie[crt][x];
		}
		end[crt]++;
	}

	void build()
	{
		fail[0] = 0;
		queue<int> q;
		for (int i = 0; i < nnode; i++) {
			if (trie[0][i]) {
				fail[trie[0][i]] = 0;
				q.push(trie[0][i]);
			} else {
				trie[0][i] = 0;
			}
		}
		while (!q.empty()) {
			int crt = q.front(); q.pop();
			for (int i = 0; i < nnode; i++) {
				if (trie[crt][i]) {
					fail[trie[crt][i]] = trie[fail[crt]][i];
					q.push(trie[crt][i]);
				} else {
					trie[crt][i] = trie[fail[crt]][i];
				}
			}
		}
	}

	int query(const char *buf)
	{
		int crt = 0;
		int res = 0;
		for (int i = 0; buf[i]; i++) {
			crt = trie[crt][buf[i] - 'a'];
			for (int j = crt; j && end[j]; j = fail[j]) {
				res += end[j];
				end[j] = 0;
			}
		}
		return res;
	}
}

char pat[60];
char str[1000010];
int n;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ac::init();
		for (int i = 0; i < n; i++) {
			scanf("%s", pat);
			ac::insert(pat);
		}
		ac::build();
		scanf("%s", str);
		printf("%d\n", ac::query(str));
	}
	return 0;
}