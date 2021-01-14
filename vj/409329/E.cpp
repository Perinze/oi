#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

char gch()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == 'T' || c == 'A' || c == 'G' || c == 'C') return c;
	}
	return '?';
}

int DNA[50][1000];
char dict[4] = {'A', 'C', 'G', 'T'};

void solve()
{
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			char c = gch();
			if (c == 'A') DNA[i][j] = 0;
			else if (c == 'C') DNA[i][j] = 1;
			else if (c == 'G') DNA[i][j] = 2;
			else if (c == 'T') DNA[i][j] = 3;
		}
	}
	
	int error = 0;
	char ans[1000];
	int times[4];	// 0 for A, 1 for C, 2 for G, 3 for T
	for (int i = 0; i < l; i++)
	{
		fill(times, times + 4, 0);
		int maxt = 0;
		for (int j = 0; j < n; j++)
		{
			maxt = max(++times[DNA[j][i]], maxt);;
		}

		int most;
		for (int k = 0; k < n; k++)
		{
			if (times[k] == maxt)
			{
				most = k;
				break;
			}
		}

		ans[i] = dict[most];
		for (int j = 0; j < n; j++)
		{
			if (DNA[j][i] != most) error++;
		}
	}
	
	for (int i = 0; i < l; i++)
	{
		putchar(ans[i]);
	}
	printf("\n%d\n", error);
}

int main()
{
	int T; scanf("%d", &T);
	for (int t = 0; t < T; t++) solve();
	return 0;
}
