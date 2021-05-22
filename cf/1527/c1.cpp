#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];
map<ll, ll> mp;
vector<ll> pos[maxn];
int n;

int main()
{
    int T;
    cin >> T;
    int cnt = 0;
    while (T--) {
        mp.clear();
        for (int i = 1; i <= cnt; i++) pos[i].clear();
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (mp[a[i]] == 0) mp[a[i]] = ++cnt;
            pos[mp[a[i]]].push_back(i);
        }
        ll ans = 0;
        for (int i = 1; i <= cnt; i++) {
            vector<ll> pre;
            pre.push_back(0);
            for (int j = 1; j <= pos[i].size(); j++)
                pre.push_back(pre[j - 1] + pos[i][j - 1]);
            for (int j = 1; j <= pos[i].size(); j++)
                ans += pre[j - 1] * (n + 1 - pos[i][j - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}