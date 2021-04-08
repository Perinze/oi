#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int mod(int x, int y)
{
    if (x >= 0) return x % y;
    return x % y + y;
}

const int MAXN = 1010;
pair<int, int> pos[MAXN];
int len;
int L, W, n, K;

void solve(int x, int y, char *dir)
{
    int vy = (dir[0] == 'N' ? 1 : -1);
    int vx = (dir[1] == 'E' ? 1 : -1);
    y += vy * K, x += vx * K;
    y = mod(y, W * 2), x = mod(x, L * 2);
    if (y <= W) pos[len].second = y;
    else pos[len].second = 2 * W - y;
    if (x <= L) pos[len].first = x;
    else pos[len].first = 2 * L - x;
    len++;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d%d", &L, &W, &n, &K);
        len = 0;
        int x0, y0;
        char dir[3];
        for (int i = 0; i < n; i++) {
            scanf("%d%d%s", &x0, &y0, dir);
            solve(x0, y0, dir);
        }
        sort(pos, pos + n);
        printf("Case %d:\n", cas);
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", pos[i].first, pos[i].second);
        }
    }
    return 0;
}