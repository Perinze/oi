#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
typedef pair<int, int> P;	//pos,gugu
int N;
vector<P> p[100010];
P map[100010];	// i-th vector<P>, i-th a

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int gugu;
		cin >> gugu;
		map[i] = P(gugu, p[gugu].size());
		p[gugu].push_back(P(i, gugu));
	}

	for (int i = 0; i < N; i++)
	{
		P tar = map[i];
		int pv = tar.first, ite = tar.second;
		if (ite == 0)	// left gugu
		{
			if (ite == p[pv].size() - 1)	// only gugu
			{
				cout << "-1 ";
			}
			else
			{
				cout << p[pv][ite + 1].first - i << ' ';
			}
		}
		else if (ite == p[pv].size() - 1)	// right gugu
		{
			cout << i - p[pv][ite - 1].first << ' ';
		}
		else // middle gugu
		{
			cout << min(p[pv][ite + 1].first - i, i - p[pv][ite - 1].first) << ' ';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
