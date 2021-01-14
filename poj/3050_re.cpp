#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define each(i, l, r) for (int i = (int)l; i < int(r); i++)

const int INF = 0x3f3f3f3f;

typedef long long ll;

int grid[5][5];
bool G[10][10];
set<string> ans;

void dfs(int v, string str)
{

	if (str.size() == 6)
		if (ans.count(str) == 0)
		{
			ans.insert(str);
			return;
		}

	each(u, 0, 10)
	{
		if (G[v][u])
		{
			string nstr = str;
			nstr.push_back(u + '0');
			dfs(u, nstr);
		}
	}
}

void solve()
{
	each(i, 0, 5)
		each(j, 0, 4)
		{
			int v = grid[i][j], u = grid[i][j + 1];
			G[v][u] = G[u][v] = true;
			v = grid[j][i], u = grid[j + 1][i];
			G[v][u] = G[u][v] = true;
		}

	each(v, 0, 10)
	{
		string s = "";
		s.push_back(v + '0');
		dfs(v, s);
	}

	set<string>::iterator ite;
	for (ite = ans.begin(); ite != ans.end(); ite++)
		cout << *ite << endl;
	cout << ans.size() << endl;
}

int main()
{
	each(i, 0, 5)
		each(j, 0, 5)
			cin >> grid[i][j];
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
