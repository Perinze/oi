#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

const int maxp = 15;
const int maxpl = 15;
const int nnode = 4;
const int maxn = 105;
const int mod = 100000;

map<char, int> id;
int n, m;
char pat[maxpl];

namespace ac {

int trie[maxn][nnode];
int fail[maxn];
int end[maxn];
int cnt;

void init()
{
	memset(trie, 0, sizeof(trie));
	memset(fail, 0, sizeof(fail));
	memset(end, 0, sizeof(end));
	cnt = 0;
}

void insert(const char *buf)
{
	int crt = 0;
	for (int i = 0; buf[i]; i++) {
		int x = id[buf[i]];
		if (!trie[crt][x])
			trie[crt][x] = ++cnt;
		crt = trie[crt][x];
	}
	end[crt] = 1;
}

void build()
{
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
				end[trie[crt][i]] |= end[trie[fail[crt]][i]];
				q.push(trie[crt][i]);
			} else {
				trie[crt][i] = trie[fail[crt]][i];
			}
		}
	}
}

}

typedef vector<ll> vec;
typedef vector<vec> mat;

mat operator*(mat &a, mat &b)
{
	int siz = a.size();
	mat c(siz, vec(siz));
	for (int i = 0; i < siz; i++)
		for (int k = 0; k < siz; k++)
			for (int j = 0; j < siz; j++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	return c;
}

mat operator^(mat &a, int n)
{
	int siz = a.size();
	mat c(siz, vec(siz));
	for (int i = 0; i < siz; i++) c[i][i] = 1;
	while (n) {
		if (n & 1) c = c * a;
		a = a * a;
		n /= 2;
	}
	return c;
}

int main()
{
	id['A'] = 0;
	id['C'] = 1;
	id['T'] = 2;
	id['G'] = 3;
	scanf("%d%d", &m, &n);
	ac::init();
	for (int i = 0; i < m; i++) {
		scanf("%s", pat);
		ac::insert(pat);
	}
	ac::build();

	int len = ac::cnt + 1;
	mat a(len, vec(len));
	for (int i = 0; i < len; i++) {
		if (!ac::end[i]) {
			for (int j = 0; j < nnode; j++) {
				if (!ac::end[ac::trie[i][j]]) {
					a[i][ac::trie[i][j]]++;
				}
			}
		}
	}
	/*
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			printf(" %d", a[i][j]);
		}
		puts("");
	}
	*/
	a = a ^ n;
	ll ans = 0;
	for (int i = 0; i < len; i++)
		ans = (ans + a[0][i]) % mod;
	printf("%lld\n", ans);
	return 0;
}