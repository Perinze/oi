#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5e5 + 10;
//int id[maxn];
int trie[maxn][26];
int res[maxn];
int fail[maxn];
int cnt = 0;

void init()
{
	//memset(id, 0, sizeof(id));
	memset(trie, 0, sizeof(trie));
	memset(res, 0, sizeof(res));
	memset(fail, 0, sizeof(fail));
	cnt = 0;
}

void insert(const char *s, int ite)
{
    int crt = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (!trie[crt][x])
            trie[crt][x] = ++cnt;
        crt = trie[crt][x];
    }
	res[crt]++;
	//id[crt] = ite;
}

void getfail()
{
	fail[0] = 0;
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (trie[0][i]) {
			fail[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	}

	while (!q.empty()) {
		int crt = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[crt][i]) {
				fail[trie[crt][i]] = trie[fail[crt]][i];
				q.push(trie[crt][i]);
			} else {
				trie[crt][i] = trie[fail[crt]][i];
			}
		}
	}
}

int query(const char *s)
{
	int ans = 0;
	int crt = 0;
	for (int i = 0; s[i]; i++) {
		crt = trie[crt][s[i] - 'a'];
		for (int j = crt; j; j = fail[j]) {
			//res[id[j]]++;
			ans += res[j];
			res[j] = 0;
		}
	}
	return ans;
}

int n;
string pat[maxn];
string str;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			cin >> pat[i];
			insert(pat[i].c_str(), i + 1);
		}
		getfail();
		cin >> str;
		cout << query(str.c_str()) << endl;
	}
	return 0;
}