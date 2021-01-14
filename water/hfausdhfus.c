#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int a;
bool used[4];
int ans[3];
int wdnmd = 0;

void print()
{
	for (int i = 0; i < 3; i++)
		printf("%d", ans[i] + a);
	if (wdnmd % 6 != 5)
		putchar(' ');
}

void dfs(int j, int step)
{
	ans[step] = j;
	if (step == 2)
	{
		print();
		wdnmd++;
		return;
	}
	used[j] = true;
	for (int i = 0; i < 4; i++)
	{
		if (!used[i])
			dfs(i, step + 1);
	}
	used[j] = false;
}

void solve()
{
	scanf("%d", &a);
	for (int i = 0; i < 4; i++)
	{
		memset(used, 0, sizeof(used));
		dfs(i, 0);
		putchar('\n');
	}
}

int main()
{
	solve();
	return 0;
}
