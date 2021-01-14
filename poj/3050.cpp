#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int grid[5][5];
set<int> ans;

void dfs(int y, int x, int step, int str)
{
	if (step == 5)
	{
		ans.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		int nstr = str * 10 + grid[ny][nx];
		dfs(ny, nx, step + 1, nstr);
	}
}

void solve()
{
	ans.clear();
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, 0, grid[i][j]);
		}

	cout << ans.size() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> grid[i][j];
	solve();
	return 0;
}
