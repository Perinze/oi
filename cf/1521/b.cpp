#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int n;
int a[maxn];
int ans[maxn][4];
int cnt;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        cnt = 0;
        for (int i = 1; i < n; i += 2) {
            ans[cnt][0] = i;
            ans[cnt][1] = i + 1;
            ans[cnt][2] = min(a[i], a[i + 1]);
            ans[cnt][3] = mod;
            cnt++;
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
        }
    }
    return 0;
}