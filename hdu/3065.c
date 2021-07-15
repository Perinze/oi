#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxp 1010
#define maxpl 60
#define maxl 2000010
#define maxn 50010
#define nnode 127

int trie[maxn][nnode];
int fail[maxn];
int id[maxn];
int res[maxp];
int cnt;

int q[maxn], front, back;

int newnode()
{
	memset(trie[cnt], 0, sizeof(trie[cnt]));
	fail[cnt] = 0;
	return cnt++;
}

void init()
{
	cnt = 0;
	memset(trie, 0, sizeof(trie));
	memset(fail, 0, sizeof(fail));
	memset(id, 0, sizeof(id));
	memset(res, 0, sizeof(res));
	newnode();
}

void insert(const char *buf, int ite)
{
	int crt = 0;
	for (int i = 0; buf[i]; i++) {
		int x = buf[i];
		if (!trie[crt][x])
			trie[crt][x] = newnode();
		crt = trie[crt][x];
	}
	id[crt] = ite;
}

void build()
{
	front = back = 0;
	fail[0] = 0;
	for (int i = 0; i < nnode; i++) {
		if (trie[0][i]) {
			fail[trie[0][i]] = 0;
			q[back++] = trie[0][i];
			back %= maxn;
		} else {
			trie[0][i] = 0;
		}
	}
	while (front != back) {
		int crt = q[front++];
		front %= maxn;
		for (int i = 0; i < nnode; i++) {
			if (trie[crt][i]) {
				fail[trie[crt][i]] = trie[fail[crt]][i];
				q[back++] = trie[crt][i];
				back %= maxn;
			} else {
				trie[crt][i] = trie[fail[crt]][i];
			}
		}
	}
}

void query(const char *buf)
{
	int crt = 0;
	memset(res, 0, sizeof(res));
	for (int i = 0; buf[i]; i++) {
		crt = trie[crt][buf[i]];
		for (int j = crt; j; j = fail[j]) {
			if (id[j]) {
				res[id[j]]++;
			}
		}
	}
}

char pat[maxp][maxpl];
char web[maxl];

/*
void read()
{
	char c;
	int p = 0;
	while ((c = getchar()) == ' ' || c == '\n');
	int prestate = (c >= 'A' && c <= 'Z' ? 0 : 1); // 0 for upper letter, 1 for invaild
	web[p++] = prestate ? 'z' + 1 : c;
	while ((c = getchar()) != EOF) {
		int state = (c >= 'A' && c <= 'Z' ? 0 : 1);
		if (prestate && state) continue;
		prestate = state;
		web[p++] = state ? 'z' + 1 : c;
	}
	web[p] = 0;
}
*/

int main()
{
	int npat;
	while (~scanf("%d", &npat)) {
		init();
		for (int i = 1; i <= npat; i++) {
			scanf("%s", pat[i]);
			insert(pat[i], i);
		}
		build();
		scanf("%s", web);
		query(web);
		for (int j = 1; j <= npat; j++) {
			if (res[j]) {
				printf("%s: %d\n", pat[j], res[j]);
			}
		}
	}
	return 0;
}