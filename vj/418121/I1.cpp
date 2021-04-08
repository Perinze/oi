#include <cstdio>
#include <map>
using namespace std;

const int MAXN = 200000;
int N, M, K;
int par[MAXN], rnk[MAXN];
int color[MAXN];
int ms[MAXN];

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
    map<int, int> s;
    map<int, int>::iterator ite;
    for (int i = 0; i < N; i++)
    {
        ite = s.find(find(i));
        if (ite == s.end())
        {
            s.insert(make_pair(find(i), s.size()));
        }
    }
    int ans = N;
    for (ite = s.begin(); ite != s.end(); ite++)
    {
        ans -= ms[*ite];
    }
    printf("%d\n", ans);
    return 0;
}