#include <stdio.h>

int main()
{
	unsigned int a, b, c;
	a = 13978152, b = 19084981, c = 98723452;

	unsigned long long num = a + b + c;
	printf("%llu\n", num);
	
	num = (unsigned long long)a + (unsigned long long)b + (unsigned long long)c;
	printf("%llu\n", num);

	return 0;
}
