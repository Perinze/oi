#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXS = 1 << 10;
const ll MAXN = 20;
const ll MAXK = 110;
ll N, K;
ll dp[MAXN][MAXK][MAXS];
ll cnt[MAXS];
ll ok[MAXS];
ll len = 0;

int main()
{
    scanf("%lld%lld", &N, &K);
    for (ll s = 0; s < (1 << N); s++) {
        ll tot = 0;
        ll sc = s;
        while (sc) {
            if (sc & 1) tot++;
            sc >>= 1;
        }
        cnt[s] = tot;
        if ((((s << 1) | (s >> 1)) & s) == 0) ok[len++] = s;
    }
    dp[0][0][0] = 1;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j < len; j++) {
            ll crt = ok[j];
            for (ll k = 0; k < len; k++) {
                ll lst = ok[k];
                if (((crt << 1) | (crt >> 1) | crt) & lst) continue;
                for (ll l = K; l >= cnt[crt]; l--) {
                    dp[i][l][crt] += dp[i - 1][l - cnt[crt]][lst];
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < len; i++) {
        ans += dp[N][K][ok[i]];
    }
    printf("%lld\n", ans);
    return 0;
}