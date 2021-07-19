#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[200005];
ll n;

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (ll i = 0; i < n; i++) cin >> a[i];
        ll ans = n * 2 - 1;
        for (ll i = 0; i + 2 < n; i++) {
            //if ((b - a) * (c - b) <= 0) ans++;
            if ((a[i + 1] - a[i]) * (a[i + 2] - a[i + 1]) < 0) ans++;
        }
        for (ll i = 0; i + 3 < n; i++) {
            if (((a[i + 1] - a[i]) * (a[i + 2] - a[i + 1]) < 0)
            && ((a[i + 1] - a[i]) * (a[i + 3] - a[i + 1]) < 0)
            && ((a[i + 2] - a[i]) * (a[i + 3] - a[i + 2]) < 0)
            && ((a[i + 2] - a[i + 1]) * (a[i + 3] - a[i + 2]) < 0))
                ans++;
        }
        cout << ans << endl;
    }
}