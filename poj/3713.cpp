#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500, MAXM = 20000;

typedef long long ll;

struct edge { int to, cap, rev; };

int N, M;
pair<int, int> es[MAXM];
vector<edge> G[MAXN];
bool used[MAXN];

void add_edge(int to, int from, int cap)
{
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f)
{
	if (v == t)
	{
		//cout << "stop at end " << t << endl;
		return f;
	}
	//cout << "get to V " << v << " with flow " << f << endl;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				//cout << "V " << v << " adjust flow " << d << endl;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
		{
			//cout << "max_flow() function returning " << flow << endl;
			return flow;
		}
		flow += f;
		if (flow == 3)
		{
			return flow;
		}
		//cout << "total flow is " << flow << " currently" << endl;
	}
}

bool safe()
{
	for (int v = 0; v < N; v++)
	{
		for (int u = v + 1; u < N; u++)
		{
			for (int i = 0; i < N; i++) 
				G[i].clear();
			for (int m = 0; m < M; m++)
			{
				int a = es[m].first, b = es[m].second;
				add_edge(a, b, 1);
				add_edge(b, a, 1);
			}
			if (max_flow(v, u) < 3)
			{
				//cout << "return when (v, u) = (" << v << ", " << u << ")\n";
				return false;
			}
			//cout << endl;
		}
	}

	return true;
}

void solve()
{
	for (;;)
	{
		cin >> N >> M;
		if (!N && !M) return;

		for (int m = 0; m < M; m++)
		{
			int a, b;
			cin >> a >> b;
			es[m] = make_pair(a, b);
		}

		if (safe()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
