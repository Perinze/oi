#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isprime(unsigned long long);
int cmp(const void*, const void*);
bool dfs(unsigned int*, unsigned long long, int, int, int, int);

void solve()
{
	int N, M;
	scanf("%d %d", &N, &M);
	unsigned int* nums = (unsigned int*)malloc(10 * sizeof(unsigned int));
	for (int n = 0; n < N; n++) scanf("%d", nums + n);
	qsort(nums, N, sizeof(unsigned int), cmp);
	if (!dfs(nums, 0, N, 0, 1, M)) printf("-1\n");
}

int main()
{
	clock_t start = clock();
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) solve();
	printf("Time: %lfs\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}

bool dfs(unsigned int* base, unsigned long long sum, int N, int p, int depth, int tardepth)
// bool stand for whether an answer has been found
{
	sum += *(base + p);
	//printf("p, depth, sum: %d, %d, %llu\n", p, depth, sum);
	if (depth == tardepth)
	{
		if (isprime(sum))
		{
			printf("%llu\n", sum);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		bool foundans = false;
		for (int np = p + 1; np < N; np++)
		{
			if (dfs(base, sum, N, np, depth + 1, tardepth))
			{
				foundans = true;
				break;
			}
		}
		return foundans;
	}
}

bool isprime(unsigned long long num)
{
	unsigned long long a;
	for (a = 2; a * a < num; a++)
		if (!(num % a)) return false;
	return true;
}

int cmp(const void* a, const void* b)
{
	return *(unsigned int*)a < *(unsigned int*)b;
}


