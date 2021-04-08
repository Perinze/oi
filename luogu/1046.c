#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* apples = (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++) scanf("%d", apples + i);
	int tall;
	scanf("%d", &tall);
	tall += 30;
	
	int res = 0;
	for (int i = 0; i < 10; i++) if (tall >= apples[i]) res++;
	printf("%d", res);

	return 0;
}
