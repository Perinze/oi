#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define INF 2e9

typedef long long ll;
const int dy[] = {-1, -2, -2, -1};
const int dx[] = {-2, -1, 1, 2};

int m, n;
bool used[200][200];

void showmap()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (used[i][j]) cout.put('o');
			else cout.put('.');
		}
		cout.put('\n');
	}
	cout.put('\n');
}

void solve(int t)
{
	cin >> m >> n;

	int ans = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		int res = 0;
		// first row
		memset(used, 0, sizeof(used));
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				used[0][j] = true;
				res++;
			}
		}

		// rest row
		for (int j = 1; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				// current pos is (j, k)
				bool here = true;
				for (int c = 0; c < 4; c++)
				{
					int ny = j + dy[c], nx = k + dx[c];
					if (ny < 0 || nx < 0 || nx >= n) continue;
					if (used[ny][nx]) 
					{
						here = false;
						break;
					}
				}
				if (here)
				{
					used[j][k] = true;
					res++;
				}
			}
		}
		ans = max(ans, res);
	}

	/*
	for (int i = 0; i < 1 << n; i++)
	{
		int res = 0;
		// first row
		memset(used, 0, sizeof(used));
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				used[0][j] = true;
				res++;
			}
		}

		// rest row
		for (int j = 1; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				// current pos is (j, k)
				bool here = true;
				for (int c = 0; c < 4; c++)
				{
					int ny = j + dy[c], nx = k + dx[c];
					if (ny < 0 || nx < 0 || nx >= n) continue;
					if (used[ny][nx]) 
					{
						here = false;
						break;
					}
				}
				if (here)
				{
					used[j][k] = true;
					res++;
				}
			}
		}
		if (res == ans) showmap();
	}
	*/

	cout << "Case " << t << ": " << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
