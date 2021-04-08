#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 70, MAXM = 32010;
int n, m;
int v[MAXN], w[MAXN];
int a[MAXN], b[MAXN];
bool mst[MAXN];
int dp[MAXM];

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(mst, 1, sizeof(mst));
        int q;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", v + i, w + i, &q);
            w[i] *= v[i];
            if (q) {
                mst[i] = false;
                if (!a[q]) a[q] = i;
                else b[q] = i;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = m; mst[i] && j >= v[i]; j -= 10) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
                if (j >= v[i] + v[a[i]])
                    dp[j] = max(dp[j], dp[j - v[i] - v[a[i]]] + w[i] + w[a[i]]);
                if (j >= v[i] + v[b[i]])
                    dp[j] = max(dp[j], dp[j - v[i] - v[b[i]]] + w[i] + w[b[i]]);
                if (j >= v[i] + v[a[i]] + v[b[i]])
                    dp[j] = max(dp[j], dp[j - v[i] - v[a[i]] - v[b[i]]] + w[i] + w[a[i]] + w[b[i]]);
            }
        printf("%d\n", dp[m]);
    }
    return 0;
}