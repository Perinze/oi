#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAXV = 110;
const int INF = 0x3f3f3f3f;

int cost[MAXV][MAXV];
int d[MAXV];
int price[MAXV];
int level[MAXV];
bool used[MAXV];
int V, m;
int ans;

int main(void)
{
    scanf("%d%d", &m, &V);
    memset(cost, 0x3f, sizeof(cost));
    for (int i = 1; i <= V; i++)
        cost[i][i] = 0;
    for (int i = 1; i <= V; i++) {
        int x;
        scanf("%d%d%d", price + i, level + i, &x);
        while (x--) {
            int v, sp;
            scanf("%d%d", &v, &sp);
            cost[v][i] = min(cost[v][i], sp);
        }
    }
    ans = price[1];
    for (int i = 1; i <= V; i++) {
        memset(used, 0, sizeof(used));
        for (int j = 1; j <= V; j++) {
            if (level[j] > level[i] + m || level[j] < level[i])
                used[j] = true;
            d[j] = price[j];
        }
        for (;;) {
            int v = -1;
            for (int u = 1; u <= V; u++) {
                if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
            }
            if (v == -1) break;
            used[v] = true;
            for (int u = 1; u <= V; u++) {
                if (d[u] > d[v] + cost[v][u] && !used[u])
                    d[u] = d[v] + cost[v][u];
            }
        }
        ans = min(ans, d[1]);
    }
    printf("%d\n", ans);
    return 0;
}