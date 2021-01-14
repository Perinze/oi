#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

//int tree[64][64];
//bool vis[64];

bool visy[8], visx[8];

int dfs(vector<P> &board, int k, int i)
{
	P p = board[i];
	if (visy[p.first] || visx[p.second]) return 0;

	if (k == 1) return 1;

	visy[p.first] = true, visx[p.second] = true;
	int res = 0;
	for (int j = i + 1; j < board.size(); j++)
	{
		res += dfs(board, k - 1, j);
	}
	visy[p.first] = false, visx[p.second] = false;

	return res;
}

void solve()
{
	for (;;)
	{
		int n, k;
		cin >> n >> k;
		if (n == -1 && k == -1) return;
	
		vector<P> board;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char c;
				while ((c = cin.get()) != '.' && c != '#');
				if (c == '#')
					board.push_back(P(i, j));
			}
		}
		
		memset(visy, 0, sizeof(visy));
		memset(visx, 0, sizeof(visx));
		int res = 0;
		for (int i = 0; i < board.size(); i++) res += dfs(board, k, i);
		cout << res << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
