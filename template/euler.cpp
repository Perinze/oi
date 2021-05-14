int euler(int n)
{
	int res = n, a = n;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			res = res / i * (i - 1);
			while (a % i == 0) a /= i;
		}
	}
	if (a > 1) res = res / a * (a - 1);
	return res;
}

// linear sieve and euler
bool is_prime[maxa]; // 0 - prime, 1 - not prime
int prime[maxn];
int phi[maxn];

int euler(int n)
{
	int cnt = 0;
	memset(is_prime, 0, sizeof(is_prime));
	is_prime[0] = is_prime[1] = 1;
	phi[1] = 1;
	for (int i = 2; i < n; i++) {
		if (is_prime[i] == 0) {
			prime[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < cnt && i * prime[j] < n; j++) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	return cnt;
}