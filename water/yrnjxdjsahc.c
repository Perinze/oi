#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print_formula(int a, int b)
{
	printf("%d*%d=%-4d", a, b, a * b);
}

void solve()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			print_formula(j, i);
		}
		putchar('\n');
	}
}

int main()
{
	solve();
	return 0;
}
