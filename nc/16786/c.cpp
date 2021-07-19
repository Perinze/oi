#include <bits/stdc++.h>
using namespace std;

const int nnode = 10;
const int maxn = 1e7 + 10;

int max_from[maxn];
int max_to[maxn];

char convert(char c)
{
	switch (c) {
		case '0': return '0';
		case '1': return '1';
		case '2': return '2';
		case '3':
		case '4': return '3';
		case '5': return '4';
		case '6':
		case '7':
		case '8':
		case '9': return '5';
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F': return '6';
		case '.': return '7';
	}
	return '8';
}

namespace ac {
	int trie[maxn][nnode];
	int end[maxn];
	int len[maxn];
	int fail[maxn];
	int cnt;
	
	void insert(const char *buf)
	{
		int crt = 0;
		for (int i = 0; buf[i]; i++) {
			int x = buf[i] - '0';
			if (!trie[crt][x])
				trie[crt][x] = ++cnt;
			crt = trie[crt][x];
		}
		end[crt]++;
		len[crt] = max(len[crt], (int)strlen(buf));
	}

	void getfail()
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
		int res = 0;
		int crt = 0;
		for (int i = 0; buf[i]; i++) {
			crt = trie[crt][convert(buf[i]) - '0'];
			for (int j = crt; j; j = fail[j]) {
				max_from[i] = max(max_from[i], len[j]);
			}
		}
		return res;
	}
}

void buildac() {
	set<string> s;
	for (int i = 0; i < 256; i++) {
		string str = "";
		int tmp = i;
		do {
			str += convert(tmp % 10 + '0');
			tmp /= 10;
		} while (tmp);
		reverse(str.begin(), str.end());
		s.insert(str);
		str = "";
		tmp = i;
		do {
			int d = tmp % 16;
			if (d < 10) d += '0';
			else d += 'A' - 10;
			str += convert(d);
			tmp /= 16;
		} while (tmp);
		reverse(str.begin(), str.end());
		s.insert(str);
	}
	for (auto s1 : s)
		for (auto s2 : s) {
			string str = s1 + '7' + s2;
			ac::insert(str.c_str());
		}
	ac::getfail();
}

char passage[10000010];

int main()
{
	buildac();
	scanf("%s", passage);
	ac::query(passage);
	int len = strlen(passage);
	for (int i = len; i > 0; i--) {
		max_to[i - max_from[i] + 1] = max(max_to[i - max_from[i] + 1], max_from[i]);
	}
	for (int pos = 0; pos < len; pos++) {
		if (max_to[pos]) {
			int next = pos + max_to[pos];
			if (next < len - 1 && passage[next] == '.' && max_to[next + 1] != 0 && next + max_to[next + 1] < len) {
				for (int i = pos; i <= next + max_to[next + 1]; i++) {
					putchar(passage[i]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}