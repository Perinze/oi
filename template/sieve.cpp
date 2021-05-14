bool is_prime[maxa];

void sieve(int n)
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i < n; i++)
		if (is_prime[i])
			for (int j = i * 2; j < n; j++)
				is_prime[j] = false;
}

// linear sieve
bool is_prime[maxa]; // 0 - prime, 1 - not prime
int prime[maxn];

int sieve(int n)
{
	int cnt = 0;
	memset(is_prime, 0, sizeof(is_prime));
	is_prime[0] = is_prime[1] = 1;
	for (int i = 2; i < n; i++) {
		if (is_prime[i] == 0) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < n; j++) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	return cnt;
}