#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

bool isprime[32769];
vector<int> prime;

void init()
{
	memset(isprime, 1, sizeof(isprime));
	isprime[1] = false;
	for (int i = 2; i <= 32768; i++)
	{
		if (isprime[i])
		{
			prime.push_back(i);
			for (int j = i * 2; j <= 32768; j += i)
			{
				isprime[j] = false;
			}
		}
	}
}

map<int, ll> dp;
ll mul(int n)
{
	if (dp[n]) return dp[n];
	ll res = n;
	while (--n)
	{
		res *= n;
	}
	return dp[n] = res;
}

void solve()
{
	int a;
	cin >> a;
	int res = 0;
	for (vector<int>::iterator ite = prime.begin(); ite != prime.end(); ite++)
	{
		if (a == 1) break;
		while (a % *ite == 0)
		{
			res++;
			a /= *ite;
		}
	}
	cout << mul(res) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
