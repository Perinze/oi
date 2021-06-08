#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> G[maxn];
int l[maxn], r[maxn];
ll dp[maxn][2];
int n;

void dfs(int v, int p = 0)
{
    dp[v][0] = dp[v][1] = 0;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] += max(dp[u][0] + llabs(l[v] - l[u]), dp[u][1] + llabs(l[v] - r[u]));
        dp[v][1] += max(dp[u][0] + llabs(r[v] - l[u]), dp[u][1] + llabs(r[v] - r[u]));
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    fill(G + 1, G + 1 + n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}