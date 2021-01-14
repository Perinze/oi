#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAXN = 16;
const int MINN = 1;
const int MINM = 1;

int main()
{
	srand(time(NULL));

	int N = 1;
	while (N <= 1)
	{
		N = rand() % (MAXN + 1);
	}
	printf("%d\n", N);

	for (int i = 1; i < N; i++)	// i is num of persons in queue
	{
		int k = 0;
		while (!k)
		{
			k = rand() % (i + 1);
		}
		int p = rand() % 2;

		printf("%d %d\n", k, p);
	}

	int M = 0;
	while (!M)
	{
		M = rand() % N;
	}
	printf("%d\n", M);

	for (int i = 0; i < M; i++)
	{
		int x = 0;
		while (!x)
		{
			x = rand() % (N + 1);
		}
		printf("%d\n", x);
	}

	return 0;
}
