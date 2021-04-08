#include <stdio.h>

int min(int a, int b)
{
	return a<b?a:b;
}

int max(int a, int b)
{
	return a>b?a:b;
}

void adjust(int* lo, int* hi)
{
	for (int i = 2; i <= *lo; i++)
		if (!(*lo % i) && !(*hi % i))
		{
			*lo /= i;
			*hi /= i;
		}
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int low = min(a, min(b, c)), high = max(a, max(b, c));
	adjust(&low, &high);
	printf("%d/%d", low, high);

	return 0;
}
