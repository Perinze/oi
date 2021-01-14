#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10000;

struct edge { int to, dis; };
vector<edge> G[MAXN];
bool infected[MAXN];
int N, M, K;

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	//printf("push %d to queue\n", source);
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		//printf("pop %d from queue\n", v);
		if (infected[v])
		{
			//printf("%d is already infected, skip\n", v);
			continue;
		}
		infected[v] = true;
		//printf("set %d infected\n", v);

		for (int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			//printf("get edge from %d to %d distance %d\n", v, e.to, e.dis);
			if (!infected[e.to] && e.dis <= K)
			{
				q.push(e.to);
				//printf("push %d to queue\n", e.to);
			}
		}
	}
}

void solve(int t)
{
	scanf("%d %d %d", &N, &M, &K);
	for (;;)
	{
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		if (!a) break;
		if (d > K) continue;
		a--; b--;
		G[a].push_back({b, d});
		G[b].push_back({a, d});
	}

	for (int i = 0; i < M; i++)
	{
		int source;
		scanf("%d", &source);
		source--;
		bfs(source);
	}
	int res = 0;
	for (int i = 0; i < N; i++)
		if (!infected[i]) res++;
	printf("%d\n", res);

	for (int i = 0; i < N; i++)
	{
		G[i].clear();
		infected[i] = false;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) solve(t);
	return 0;
}
