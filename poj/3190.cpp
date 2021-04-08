#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
//typedef pair<int, int> P;
struct P
{
	int id, l, r;
	bool operator <(const P s)
	{
		if (r == s.r) return l < s.l;
		return r < s.r;
	}
};

int N;
vector<P> cows;
int stall[50000];

void solve()
{
	sort(cows.begin(), cows.end());
	int ans = 0;
	while (!cows.empty())
	{
		int r = cows[0].r;
		stall[cows[0].id] = ans + 1;
		cows.erase(cows.begin());
		for (vector<P>::iterator ite = cows.begin(); ite != cows.end(); ite++)
		{
			if (ite->l > r)
			{
				r = ite->r;
				stall[ite->id] = ans + 1;
				cows.erase(ite);
				ite--;
			}
		}
		ans++;
	}

	printf("%d\n", ans);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", stall[i]);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		P p;
		p.id = i;
		p.l = a;
		p.r = b;
		cows.push_back(p);
	}
	solve();
	return 0;
}
