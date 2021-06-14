#include <bits/stdc++.h>
using namespace std;

const int siz = 1e5 + 10;
bool is_prime[siz];
vector<int> prime;

void sieve()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 1e5; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= 1e5; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int get(int x)
{
	int res = 0;
	for (int i = 0; i < prime.size(); i++) {
		while (x % prime[i] == 0) {
			//cout << "prime" << prime[i] << endl;
			x /= prime[i];
			//cout << "x " << x << endl;
			res++;
			if (x == 1) break;
		}
	}
	if (x != 1) res++;
	return res;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	sieve();
	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;
		if (k == 1) {
			if (a == b) cout << "NO" << endl;
			else if (gcd(a, b) == min(a, b)) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}
		//cout << get(a) << endl;
		//cout << get(b) << endl;
		if (get(a) + get(b) >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}