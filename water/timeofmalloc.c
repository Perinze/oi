#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int *small, *large;
	clock_t starttest = clock();
	small = (int*)malloc(100*sizeof(int));
	printf("test: %lf\n", (double)(clock() - starttest) / CLOCKS_PER_SEC);

	clock_t startsmall = clock();
	small = (int*)malloc(100*sizeof(int));
	printf("small: %lf\n", (double)(clock() - startsmall) / CLOCKS_PER_SEC);

	clock_t startlarge = clock();
	large = (int*)malloc(10000000*sizeof(int));
	printf("large: %lf\n", (double)(clock() - startlarge) / CLOCKS_PER_SEC);

	return 0;
}
