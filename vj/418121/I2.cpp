#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 200000;
int N, M, K;
int par[MAXN], rnk[MAXN];
int color[MAXN];
vector<int> root;
bool vis[MAXN];
map<int, int> db[MAXN];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rnk[x] < rnk[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    init(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", color + i);
        color[i]--;
    }
    for (int i = 0; i < M; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--; r--;
        unite(l, r);
        vis[l] = vis[r] = true;
    }
    for (int i = 0; i < N; i++)
    {
        if (vis[i])
        {
            if (par[i] == i) root.push_back(i);

            db[find(i)][color[i]] = 0;
        }
    }
    for (int i = 0; i < N; i++)
        if (vis[i])
            db[find(i)][color[i]]++;
    int ans = 0;
    for (int r = 0; r < root.size(); r++)
    {
        int sum = 0, m = 0;
        for (map<int, int>::iterator ite = db[root[r]].begin(); ite != db[root[r]].end(); ite++)
        {
            sum += ite->second;
            m = max(m, ite->second);
        }
        ans += sum - m;
    } 
    printf("%d\n", ans);
    return 0;
}