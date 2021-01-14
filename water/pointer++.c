#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(sizeof(int));
	*p = 1;
	printf("%d\n", *p);
	*p++;
	printf("%d\n", *p);
	return 0;
}
