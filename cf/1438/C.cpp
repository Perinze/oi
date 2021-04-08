#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

int N, M;
int b[100][100];

void solve()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int a; cin >> a;
			if (a % 2 != (i + j) % 2)
			{
				b[i][j] = a + 1;
			}
			else
			{
				b[i][j] = a;
			}
		}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << b[i][j] << ' ';	
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
