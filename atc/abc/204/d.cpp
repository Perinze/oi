#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxt = 1010;
int n;
int a[maxn];
bool dp[maxn][maxn * maxt];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] = dp[i][j] || dp[i - 1][j - a[i]];
        }
    }
    int ans;
    for (int i = (sum + 1) / 2; i <= sum; i++) {
        if (dp[n][i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}