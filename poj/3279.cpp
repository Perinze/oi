#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const int dy[5] = {0, -1, 0, 1, 0};
const int dx[5] = {0, 0, -1, 0, 1};

int M, N;
int tile[15][15];

int flip[15][15];
int opt[15][15];

int get(int y, int x)
{
	int c = tile[y][x];
	for (int i = 0; i < 5; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N)
		{
			c += flip[ny][nx];
		}
	}
	return c % 2;
}

void solve()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tile[i][j];
		}
	}

	int ans = -1;
	for (int i = 0; i < 1 << N; i++)
	{
		memset(flip, 0, sizeof(flip));
		for (int j = 0; j < N; j++)
		{
			flip[0][j] = i >> j & 1;
		}
		
		for (int j = 1; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (get(j - 1, k))	// not 0
				{
					// to be fliped
					flip[j][k] = 1;
				}
			}
		}

		bool failed = false;
		for (int j = 0; j < N; j++)
		{
			if (get(M - 1, j))	// not 0
			{
				failed = true;
			}
		}
		if (failed) continue;

		// successful
		int res = 0;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (flip[j][k]) res++;
			}
		}

		if (ans < 0 || res < ans)
		{
			ans = res;
			memcpy(opt, flip, sizeof(flip));
		}
	}

	if (ans < 0)
		cout << "IMPOSSIBLE" << endl;
	else
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << opt[i][j] << ' ';
			}
			cout << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
