#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

const int MAXN = 100;

int N;
vector<int> G[MAXN + 1];
int W[MAXN + 1];
bool vis[MAXN + 1];

int dfs(int v, int d)
{
	if (vis[v]) return 0;
	vis[v] = true;

	int res = W[v] * d;
	//printf("dfs(%d, %d) value %d\n", v, d, res);
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		res += dfs(u, d + 1);
	}
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int w;	// number of people
		int u, v;	// nearest node
		scanf("%d %d %d", &w, &u, &v);
		if (u)
		{
			G[i].push_back(u);
			G[u].push_back(i);
		}
		if (v)
		{
			G[i].push_back(v);
			G[v].push_back(i);
		}
		W[i] = w;
	}
	int res = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		fill(vis + 1, vis + N + 1, false);
		res = min(res, dfs(i, 0));
		//printf("dfs start from %d value %d\n", i, dfs(i, 0));
		//putchar('\n');
	}
	printf("%d\n", res);

	return 0;
}
