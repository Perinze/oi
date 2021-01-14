#include <stdio.h>

int main()
{
	float t; int n;
	scanf("%f %d", &t, &n);
	printf("%.3f\n%d", t / (float)n, n * 2);
	return 0;
}
