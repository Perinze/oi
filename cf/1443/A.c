#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0, j = 4 * n; i < n && j > 2 * n; i++, j -= 2)
		{
			printf("%d ", j);
		}
		putchar('\n');
	}
	return 0;
}
