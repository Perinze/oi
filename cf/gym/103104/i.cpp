#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int maxn = 5010;
int n, m;
bool mat[maxn][maxn];
int h[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a][b] = true;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (!mat[i][j]) h[i][j] = h[i - 1][j] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<pii> stk;
        for (int j = 1; j <= n; j++) {
            int w = 0;
            int x = h[i][j];
            pii tp;
            if (!stk.empty() && x < (tp = stk.top()).first) {
                ans += (tp.first - x) * (tp.second * w + (tp.second + 1) * tp.second / 2);
                w += tp.second;
            }
            stk.push(pii{x, w + 1});
        }
    }
    cout << ans << endl;
    return 0;
}