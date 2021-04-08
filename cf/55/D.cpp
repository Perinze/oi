#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const ll mod = 2520;
ll dp[20][mod + 10][50];
int map[mod + 10];
int top[20];

ll gcd(ll a, ll b)
{
    return b? gcd(b, a % b): a;
}

ll glcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll dfs(int len, ll num, ll lcm, bool flag)
{
    if (len == -1) return num % lcm == 0;
    if (!flag && ~dp[len][num][map[lcm]]) return dp[len][num][map[lcm]];
    ll ans = 0;
    int end = flag? top[len]: 9;
    for (int i = 0; i <= end; i++)
        ans += dfs(len - 1, (num * 10 + i) % mod, i? glcm(lcm, i): lcm, flag && i == end);
    if (!flag) dp[len][num][map[lcm]] = ans;
    return ans;
}

ll solve(ll n)
{
    int p = 0;
    while (n) {
        top[p++] = n % 10;
        n /= 10;
    }
    return dfs(p - 1, 0, 1, true);
}

int main()
{
    int T;
    cin >> T;
    int cnt = 0;
    for (int i = 1; i <= mod; i++)
        if (mod % i == 0)
            map[i] = cnt++;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}