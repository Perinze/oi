#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 500010
#define nnode 26

int trie[maxn][nnode];
int fail[maxn];
int end[maxn];
int cnt;
int q[maxn], front, back;

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
	front = back = 0;
	fail[0] = 0;
	for (int i = 0; i < nnode; i++) {
		if (trie[0][i]) {
			fail[trie[0][i]] = 0;
			q[back++] = trie[0][i]; back %= maxn;
		} else {
			trie[0][i] = 0;
		}
	}
	while (front != back) {
		int crt = q[front++]; front %= maxn;
		for (int i = 0; i < nnode; i++) {
			if (trie[crt][i]) {
				fail[trie[crt][i]] = trie[fail[crt]][i];
				q[back++] = trie[crt][i]; back %= maxn;
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

char pat[60];
char str[1000010];
int n;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", pat);
			insert(pat);
		}
		build();
		scanf("%s", str);
		printf("%d\n", query(str));
	}
	return 0;
}