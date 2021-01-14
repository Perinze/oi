#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 67108863;
char tree[MAXN];
int map['z'+1];

void dfs(int s)
{
	if (tree[s] == 0) return;
	cout << tree[s];
	dfs(s*2+1);
	dfs(s*2+2);
}

int main()
{
	ios::sync_with_stdio(false);
	fill(tree, tree+MAXN, 0);
	fill(map, map+'z', -1);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if (i == 0)	// new node
		{
			tree[0] = p; map[p] = 0;
			if (l != '*')
			{
				tree[1] = l;
				map[l] = 1;
			}
			if (r != '*')
			{
				tree[2] = r;
				map[r] = 2;
			}
		}
		else
		{
			int pp, pl, pr;
			pp = map[p];
			if (l != '*')
			{
				pl = pp * 2 + 1;
				tree[pl] = l;
				map[l] = pl;
			}
			if (r != '*')
			{
				pr = pp * 2 + 2;
				tree[pr] = r;
				map[r] = pr;
			}
		}
	}
	
	dfs(0);
	return 0;
}
