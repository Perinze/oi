#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int max(int a, int b)
{
	return a > b? a: b;
}

int min(int a, int b)
{
	return a < b? a: b;
}

void solve()
{
	int a, b;
	scanf("%d/%d", &a, &b);
	int com = gcd(max(a, b), min(a, b));
	printf("%d/%d", a / com, b / com);
}

int main()
{
	solve();
	return 0;
}
