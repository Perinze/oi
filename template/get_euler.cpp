#include <iostream>
#include <cstring>

const int maxn = 1000, maxa = 1000;

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
				// absolutely not necessary to use phi[i * prime[j]] = phi[i] * prime[j] which is hard to understand
				// but maybe a little little bit faster, and it is just correct
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	return cnt;
}

int main()
{
    euler(maxn);
    int n;
    std::cin >> n;
    std::cout << phi[n] << std::endl;
    return 0;
}