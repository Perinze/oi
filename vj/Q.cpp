#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
const int MAXN = 10000;

int phi[MAXN + 1];
int map[1000001];

void init()
{
	memset(phi, 0, sizeof(phi));
	memset(map, 0x3f, sizeof(map));
	map[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	{
		if (!phi[i])
		{
			for (int j = i; j <= MAXN; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}

}

void solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	for (int i = 1; i <= 15; i++)
		cout << phi[i] << endl;
	cout << endl;
	for (int i = 1; i <= 15; i++)
		cout << map[i] << endl;
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
