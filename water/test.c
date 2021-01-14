#include <stdio.h>
#include <math.h>

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++) a[i] = i;
	// a = 0, 1, 2, ..., 9
	int *p = a + 2;
	printf("%d\n", a[2]);
	printf("%d\n", p[3]);
	printf("%d\n", *(a + 5));
	printf("%d\n", *(p - 1));
	return 0;
}
