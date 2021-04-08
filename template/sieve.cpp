bool is_prime[MAXN];

void sieve(int n)
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i < n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * 2; j < n; j++)
			{
				is_prime[j] = false;
			}
		}
	}
}
