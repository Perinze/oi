#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
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

	map<int, int> roots;
	map<int, int>::iterator ite;
	for (int i = 0; i < n; i++)
	{
		int root = find(i);
		//if (roots.count(root) == 0)
		ite = roots.find(root);
		if (ite == roots.end())
		{
			roots.insert(make_pair(root, p[i]));
		}
		if (p[i] < ite->second)
		{
			roots.erase(root);
			roots.insert(make_pair(root, p[i]));
		}
	}

	ll res = 0;
	//for (int i = 0; i < roots.size(); i++)
	for (ite = roots.begin(); ite != roots.end(); ++ite)
	{
		//res += mincost[roots[i]] * mincost[roots[i]];
		res += ite->second * ite->second;
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
