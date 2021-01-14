#include <stdio.h>

int log(int x)
{
	int r = 0;
	while (x >>= 1) r++;
	return r;
}

int main()
{
	for (int i = 0; i < 128; i++)
	{
		printf("log(%d)=%d\n", i, log(i));
	}
	return 0;
}
