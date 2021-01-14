#include <iostream>
using namespace std;

int depth = 0;
struct family
{
	int a, b;
} tree[1000010];

void dfs(int p, int lvl)
{
	if (p == -1) return;
	depth = max(depth, lvl);
	dfs(tree[p].a, lvl+1); dfs(tree[p].b, lvl+1);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int na, nb;
		cin >> na; na--;
		cin >> nb; nb--;
		tree[i] = {na, nb};
	}

	dfs(0, 1);
	cout << depth;

	return 0;
}
