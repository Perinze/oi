#include <cstdio>
#include <map>
using namespace std;

typedef pair<int, int> P;
const int MAXN = 200000;
int N, M, K;
int par[MAXN], rnk[MAXN];
int color[MAXN];
map<int, map<int, int> > sockmap;

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
    }
    map<int, map<int, int> >::iterator ite;
    map<int, int>::iterator jte;
    for (int i = 0; i < N; i++)
    {
        ite = sockmap.find(find(i));
        jte = ite->second.find(color[i]);
        if (jte == ite->second.end())
            sockmap[find(i)][color[i]] = 1;
        else
            sockmap[find(i)][color[i]]++;
    }
    int ans = 0;
    for (ite = sockmap.begin(); ite != sockmap.end(); ite++)
    {
        int sum = 0, mx = 0;
        for (jte = ite->second.begin(); jte != ite->second.end(); jte++)
        {
            sum += jte->second;
            mx = max(jte->second, mx);
        }
        ans += sum - mx;
    }
    printf("%d\n", ans);
    return 0;
}