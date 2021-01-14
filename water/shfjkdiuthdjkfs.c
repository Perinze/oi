#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
void print_star(int t, char c)
{
	for (int i = 0; i < n - 1 - t; i++)
		putchar(' ');
	putchar(c);
	if (t != 0)
	{
		for (int i = 0; i < (t - 1) * 2 + 1; i++)
			putchar(' ');
		putchar(c);
	}
	putchar('\n');
}

void solve()
{
	char c; scanf("%c %d", &c, &n);
	n = (n + 1) / 2;
	for (int i = 0; i < n; i++)
	{
		print_star(i, c);
		c++;
	}
	c -= 2;
	for (int i = n - 2; i >= 0; i--)
	{
		print_star(i, c);
		c--;
	}
}

int main()
{
	solve();
	return 0;
}
