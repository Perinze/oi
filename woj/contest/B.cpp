#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = 1000000001;
int n, z;
int p[100000];

int mincost[100000];

int par[100000], rk[100000];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rk[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rk[x] < rk[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rk[x] == rk[y]) rk[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

void solve()
{
	fill(mincost, mincost + 100000, INF);
	cin >> n >> z;
	init(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((p[i] + p[j]) % z == 0)
			{
				unite(i, j);
			}
		}
	}

	vector<int> roots;
	for (int i = 0; i < n; i++)
	{
		roots.push_back(find(i));
	}
	sort(roots.begin(), roots.end());
	roots.erase(unique(roots.begin(), roots.end()), roots.end());

	for (int i = 0; i < n; i++)
	{
		int root = find(i);
		mincost[root] = min(mincost[root], p[i]);
	}

	ll res = 0;
	for (int i = 0; i < roots.size(); i++)
	{
		res += mincost[roots[i]] * mincost[roots[i]];
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
