#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool isprime[501];

void init()
{
	isprime[0] = false;
	isprime[1] = false;
	for (int i = 2; i <= 500; i++)
	{
		if (isprime[i])
		{
			for (int j = i * 2; j <= 500; j += i)
			{
				isprime[j] = false;
			}
		}
	}
}

void solve()
{
	memset(isprime, 1, sizeof(isprime));
	init();
	int l, r;
	scanf("%d %d", &l, &r);
	int ans = 0, total = 0;
	for (int i = l; i <= r; i++)
	{
		if (isprime[i])
		{
			ans += i;
			total++;
		}
	}
	printf("%d %d\n", total, ans);
}

int main()
{
	solve();
	return 0;
}
