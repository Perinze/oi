#include <stdio.h>
#include <stdlib.h>

void push_back(int*, int*, int);

int main()
{
	int N;
	scanf("%d", &N);

	// init
	int* size = (int*)calloc(0, N * sizeof(int));
	int** db = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
		db[i] = (int*)malloc(0);

	// insert data
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			push_back(db[i], size + i, j);

	// read data
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("%d ", db[i][j]);
		putchar('\n');
	}
	
	// free memory
	free(size);
	for (int i = 0; i < N; i++)
		free(db[i]);

	return 0;
}

void push_back(int* vla, int* size, int dat)
{
	(*size)++;
	vla = realloc(vla, (*size) * sizeof(int));
	vla[(*size) - 1] = dat;
}
