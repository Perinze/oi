const int MAXV = 100;

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

#if defined (__i386__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned long long int x;
    __asm__ volatile("rdtsc": "=A"(x));
    return x;
}
#elif defined (__x86_64__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned hi, lo;
    __asm__ volatile("rdtsc": "=a"(lo), "=d"(hi));
    return ((unsigned long long) lo) | (((unsigned long long) hi) << 32);
}
#endif

#define FREQUENCY 3593.0000

int main()
{
    unsigned long t1, t2;
    t1 = (unsigned long)GetCycleCount();
	solve();
    t2 = (unsigned long)GetCycleCount();
    printf("time: %f\n", (t2 - t1) * 1.0 / FREQUENCY);
}