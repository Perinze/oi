#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxpl 210
#define maxp 510
#define maxn 100010
#define maxm 1010
#define maxl 10010
#define nnode 128

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

char pat[maxpl];
char web[maxl];

int main()
{
	init();
	int npat;
	scanf("%d", &npat);
	for (int i = 1; i <= npat; i++) {
		scanf("%s", pat);
		insert(pat, i);
	}
	build();
	int tot = 0;
	int nweb;
	scanf("%d", &nweb);
	for (int i = 1; i <= nweb; i++) {
		scanf("%s", web);
		query(web);
		int infected = 0;
		for (int j = 1; j <= npat; j++) {
			if (res[j]) {
				infected = 1;
				break;
			}
		}
		if (infected) {
			tot++;
			printf("web %d:", i);
			for (int j = 1; j <= npat; j++) {
				if (res[j]) {
					printf(" %d", j);
				}
			}
			printf("\n");
		}
	}
	printf("total: %d\n", tot);
	return 0;
}