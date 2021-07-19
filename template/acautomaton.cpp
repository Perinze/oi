using ll = long long;

namespace ac {
	const ll nnode = 26;
	const ll maxn = 5e5 + 10;

	ll trie[maxn][nnode];
	ll res[maxn];
	ll fail[maxn];
	ll cnt;
	
	void init()
	{
		cnt = 0;
		memset(trie, 0, sizeof(trie));
		memset(res, 0, sizeof(res));
		memset(fail, 0, sizeof(fail));
	}

	void insert(const char *s, int ite)
	{
		ll crt = root;
		for (ll i = 0; s[i]; i++) {
			ll x = s[i] - 'a';
			if (!trie[crt][x])
				trie[crt][x] = ++cnt;
			crt = trie[crt][x];
		}
		res[crt]++;
	}

	void getfail()
	{
		fail[root] = root;
		queue<ll> q;
		for (ll i = 0; i < nnode; i++) {
			if (trie[root][i]) {
				fail[trie[root][i]] = root;
				q.push(trie[root][i]);
			} else {
				trie[root][i] = root;
			}
		}
		while (!q.empty()) {
			ll crt = q.front(); q.pop();
			for (ll i = 0; i < nnode; i++) {
				if (trie[crt][i]) {
					fail[trie[crt][i]] = trie[fail[crt]][i];
					q.push(trie[crt][i]);
				} else {
					trie[crt][i] = trie[fail[crt]][i];
				}
			}
		}
	}

	ll query(const char *s)
	{
		ll ans = 0;
		ll crt = root;
		for (ll i = 0; s[i]; i++) {
			crt = trie[crt][s[i] - 'a'];
			for (ll j = crt; j; j = fail[j]) {
				ans += res[j];
				res[j] = 0;
			}
		}
		return ans;
	}
}