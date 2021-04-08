#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;

typedef long long ll;
typedef pair<int, int> P;
int from, to;

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
			for (int j = i * 2; j < n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}

int digit(int n, int i)
{
	int mod = 1;
	for (int j = 0; j < i; j++) mod *= 10;
	n /= mod;
	return n % 10;
}

int ch_digit(int n, int i, int t)
{
	int mod = 1;
	for (int j = 0; j < i; j++) mod *= 10;
	return n + (t - digit(n, i)) * mod;
}

int vis[MAXN];

void solve()
{
	if (from == to)
	{
		cout << 0 << endl;
		return;
	}
	memset(vis, -1, sizeof(vis));
	queue<int> q;
	q.push(from);
	vis[from] = 0;
	while (!q.empty())
	{
		int num = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				int nnum = ch_digit(num, i, j);
				if (nnum < 1000) continue;
				/*
				cout << nnum << endl;
				string cao;
				getline(cin, cao);
				cout << "is_prime[" << nnum << "] = " << is_prime[nnum] << endl;
				*/
				if (is_prime[nnum] && vis[nnum] == -1)
				{
					vis[nnum] = vis[num] + 1;
					if (nnum == to)
					{
						cout << vis[nnum] << endl;
						return;
					}
					q.push(nnum);
				}
			}
		}
	}
	cout << "Not found\n";
}

int main()
{
	ios::sync_with_stdio(false);
	sieve(MAXN);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> from >> to;
		solve();
	}
	return 0;
}
