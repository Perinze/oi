#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
const ll maxn = 20010;
const ll maxm = 100010;
const ll mod = 1000000007;
ll bsz;
struct node {
	ll l, r, id;
	bool operator<(const node &s) const {
		if (l / bsz != s.l / bsz) return l < s.l;
		if ((l / bsz) & 1) return r < s.r;
		return r > s.r;
	}
};
ll n, m;
ll cnt[maxn];
ll sun[maxn];
node query[maxm];
ll ans[maxn];
ll pre[maxn];
ll res;

ll mod_pow(ll b, ll t)
{
	ll res = 1;
	while (t) {
		if (t & 1) res = res * b % mod;
		b = b * b % mod;
		t >>= 1;
	}
	return res;
}

void add(ll x)
{
	res = (res - mod_pow(1 + cnt[x], x) * cnt[x]) % mod;
	cnt[x]++;
	res = (res + mod_pow(1 + cnt[x], x) * cnt[x]) % mod;
}

void del(ll x)
{
	res = (res - mod_pow(1 + cnt[x], x) * cnt[x]) % mod;
	cnt[x]--;
	res = (res + mod_pow(1 + cnt[x], x) * cnt[x]) % mod;
}

int main()
{
	ios::sync_with_stdio(false);
	ll l, r;

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> sun[i];
	for (ll i = 1; i <= n; i++) {
		ll d;
		cin >> d;
		l = max(i - d, 1ll), r = min(i + d, n);
		query[i] = node{l, r, i};
	}
	bsz = (ll)sqrt(n);
	sort(query + 1, query + 1 + n);
	l = 1, r = 0;
	//res = 0;
	for (ll i = 1; i <= n; i++) {
		while (l > query[i].l) add(sun[--l]);
		while (l < query[i].l) del(sun[l++]);
		while (r > query[i].r) del(sun[r--]);
		while (r < query[i].r) add(sun[++r]);
		ans[query[i].id] = res;
	}
	for (ll i = 1; i <= n; i++) {
		pre[i] = (pre[i - 1] + ans[i]) % mod;
	}
	for (ll i = 0; i < m; i++) {
		cin >> l >> r;
		cout << ((pre[r] - pre[l - 1]) % mod + mod) % mod << endl;
	}

	return 0;
}