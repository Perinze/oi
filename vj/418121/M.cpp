#include <cstdio>
#include <cstring>

typedef long long unsigned ll;
const int MAXN = 5000010;
ll dp[MAXN];

void euler()
{
	memset(dp, 0, sizeof(dp));
    dp[1] = 1;
	for (ll i = 2; i <= MAXN; i++)
	{
		if (!dp[i])
		{
			for (ll j = i; j <= MAXN; j += i)
			{
				if (!dp[j]) dp[j] = j;
				dp[j] = dp[j] / i * (i - 1);
			}
		}
	}
}

void init()
{
    euler();
    ll sum = 0;
    for (int i = 1; i <= MAXN; i++)
    {
        sum += dp[i] * dp[i];
        dp[i] = sum;
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int a, b;
        scanf("%d%d", &a, &b); a--;
        printf("Case %d: %llu\n", t, dp[b] - dp[a]);
    }
    return 0;
}