#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char name[10][11];
int score[10][8];
int max[10], min[10];
float final[10];

void solve()
{
	memset(min, 0x3f, sizeof(min));
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", score[i] + j);
			max[i] = score[i][j] > max[i]? score[i][j]: max[i];
			min[i] = score[i][j] < min[i]? score[i][j]: min[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		float sum = 0;
		for (int j = 0; j < m; j++)
			sum += score[i][j];
		final[i] = (sum - max[i] - min[i]) / (m - 2.0);
	}

	bool used[10];
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++)
	{
		float m = 0; int p;
		for (int j = 0; j < n; j++)
		{
			if (used[j]) continue;
			if (final[j] > m)
			{
				m = final[j];
				p = j;
			}
		}
		printf("%d %s %.1f\n", i, name[p], final[p]);
		used[p] = true;
	}
}

int main()
{
	solve();
	return 0;
}
