#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105, MAXM = 10, INF = 0x3f3f3f3f;
int dp[MAXN][70][70];
int n, m;
int map[MAXN];
int sel[70];
int cnt[70];
int len = 0;

int main()
{
    scanf("%d%d", &n, &m);

    for (int s = 0; s < (1 << m); s++) {
        int sc = s;
        int res = 0;
        while (sc) {
            if (sc & 1) res++;
            sc >>= 1;
        }
        //printf("cnt[%d]=%d\n", s, cnt[s]);
        int msk = (s << 1) | (s << 2) | (s >> 1) | (s >> 2);
        if ((msk & s) == 0) {
            sel[len] = s;
            cnt[len] = res;
            len++;
        }
    }

    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = 1; j <= m; j++) {
            char c;
            while ((c = getchar()) != 'P' && c != 'H');
            s <<= 1;
            s |= (c == 'H' ? 1 : 0);
        }
        map[i] = s;
    }

    for (int i = 0; i < len; i++) {
        int s = sel[i];
        if (s & map[1]) continue;
        dp[1][s][0] = cnt[i];
    }

    for (int i = 0; i < len; i++) {
        int s = sel[i];
        if (s & map[2]) continue;
        for (int j = 0; j < len; j++) {
            int s1 = sel[j];
            if (s1 & map[1]) continue;
            if (s & s1) continue;
            dp[2][s][s1] = max(dp[2][s][s1], dp[1][s1][0] + cnt[i]);
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < len; j++) {
            int s = sel[j];
            if (s & map[i]) continue;
            for (int k = 0; k < len; k++) {
                int s1 = sel[k];
                if (s1 & map[i - 1]) continue;
                if (s & s1) continue;
                for (int l = 0; l < len; l++) {
                    int s2 = sel[l];
                    if (s2 & map[i - 2]) continue;
                    if (s & s2) continue;
                    dp[i][s][s1] = max(dp[i][s][s1], dp[i - 1][s1][s2] + cnt[i]);
                }
            }
        }
    }

    int ans = 0;
    for (int k = 1; k < len; k++) {
        ans = 0;
        int line, crt_s, lst_s;
    for (int i = 0; i < len; i++) {
        int s = sel[i];
        for (int j = 0; j < len; j++) {
            int s1 = sel[i];
            if (s & s1) continue;
            if (s & map[n]) continue;
            if (s1 & map[n - 1]) continue;
            ans = max(dp[k][s][s1], ans);
            if (dp[k][s][s1] > ans) {
                ans = dp[k][s][s1];
                line = k;
                crt_s = s;
                lst_s = s1;
            }
        }
    }
    printf("dp[%d][%d][%d]: %d\n", line, crt_s, lst_s, ans);
    }
    printf("%d\n", ans);

    return 0;
}