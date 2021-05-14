#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const ll maxn = 20010;
ll n, bit[2][maxn];
P cow[maxn];

ll query(ll *bit, ll i_)
{
	ll s = 0;
	for (ll i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

void add(ll *bit, ll i_, ll x)
{
	for (ll i = i_; i <= maxn; i += i & -i)
		bit[i] += x;
}

int main()
{
    cin >> n;
    ll v, p;
    for (ll i = 1; i <= n; i++) {
        cin >> v >> p;
        cow[i] = P(v, p);
    }
    sort(cow + 1, cow + 1 + n);
    ll ans = 0;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        ll res = 0;
        res += query(bit[1], cow[i].second) * cow[i].second - query(bit[0], cow[i].second);
        //cout << "log: res += " << query(bit[1], cow[i].second) * cow[i].second - query(bit[0], cow[i].second) << endl;
        res += (sum - query(bit[0], cow[i].second)) - (i - 1 - query(bit[1], cow[i].second)) * cow[i].second;
        //cout << "log: res += " << (sum - query(bit[0], cow[i].second)) - (i - 1 - query(bit[1], cow[i].second)) * cow[i].second << endl;
        //cout << "log: ans += " << res * cow[i].first << endl;
        ans += res * cow[i].first;
        add(bit[0], cow[i].second, cow[i].second);
        add(bit[1], cow[i].second, 1);
        sum += cow[i].second;
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}