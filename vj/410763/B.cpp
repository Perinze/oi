#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXV = 210;

typedef long long ll;

int n, m;
int a[100], b[100];

struct edge { int to, cap, rev; };

vector<edge> G[MAXV];
bool used[MAXV];

void add_edge(int to, int from, int cap)
{
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f)
{
	if (v == t) return f;
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
		if (f == 0) return flow;
		flow += f;
	}
}

bool inrange(int a, int b)
{
	int d = a - b;
	if (d < 0) d *= -1;
	if (d <= 1) return true;
	return false;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	// connect from s-0 to each boy 1-n
	for (int i = 0; i < n; i++)
	{
		//cout << 0 << "->" << i + 1 << endl;
		add_edge(i + 1, 0, 1);
	}
	// connect from each boy to each girl
	// boys are ordered 1 to n
	// girls are ordered n + 1 to n + m
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (inrange(a[i], b[j]))
			{
				//cout << i + 1 << "->" << n + 1 + j << endl;
				add_edge(n + 1 + j, i + 1, 1);
			}
		}
	}
	// connect from each girl to t- n+m+1
	for (int j = 0; j < m; j++)
	{
		//cout << n + 1 + j << "->" << n + m + 1 << endl;
		add_edge(n + m + 1, n + 1 + j, 1);
	}

	int ans = max_flow(0, n + m + 1);
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
