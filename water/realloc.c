#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int a, b, c;
} stc;

unsigned int size;
stc* vla;

void init_vla()
{
	size = 0;
	vla = (stc*)malloc(size * sizeof(stc));
}

void push_back(stc value)
{
	size++;
	vla = (stc*)realloc(vla, size * sizeof(stc));
	if (vla == NULL)
	{
		printf("realloc failed\n");
		size--;
	}
	vla[size - 1] = value;
}

int main()
{
	unsigned int N;
	scanf("%u", &N);

	clock_t start = clock();

	init_vla();
	for (int i = 0; i < N; i++)
	{
		push_back({i, i+1, i+2});
	}
	for (int i = 0; i < N; i++) printf("%d %d %d\n", vla[i].a, vla[i].b, vla[i].c);

	printf("\n%lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}
