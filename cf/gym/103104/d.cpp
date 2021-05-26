#include <cstdio>
#include <cstring>

const int maxn = 5e3 + 10;
bool vis[maxn];
int a[maxn];
int n;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            a[x] = i;
        }
        if (n == 1) {
            puts("0");
            continue;
        }
        int ans = 0;
        for (int l = 1; l <= n; l++) {
            memset(vis, 0, sizeof(vis));
            int cnt = 0;
            for (int r = l; r <= n; r++) {
                if (vis[a[r] - 1] && vis[a[r] + 1])
                    cnt--;
                else if (vis[a[r] - 1] || vis[a[r] + 1])
                    ;
                else
                    cnt++;
                //printf("[%d, %d] %d\n", l, r, cnt);
                if (cnt <= 2) ans++;
                vis[a[r]] = true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}