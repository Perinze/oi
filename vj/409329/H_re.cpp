#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool visy[8], visx[8];

bool exam(vector<P> &board, int n, int comb)
{
	memset(visy, 0, sizeof(visy));
	memset(visx, 0, sizeof(visx));

	for (int i = 0; i < n; i++)
	{
		if (comb >> i & 1)
		{
			P p = board[i];
			if (visy[p.first] || visx[p.second]) return false;
			visy[p.first] = true, visx[p.second] = true;
		}
	}
	return true;
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
		
		int res = 0;

		ll comb = (1 << k) - 1;
		while (comb < 1 << n) {
			if (exam(board, n, comb)) res++;
			
			ll x = comb & -comb, y = comb + x;
			comb = ((comb & ~y) / x >> 1) | y;
		}
		cout << res << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
