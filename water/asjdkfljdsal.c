#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_int(double x)
{
	if (x == (double)(int)x) return true;
	return false;
}

void solve()
{
	double R2;
	scanf("%lf", &R2);
	bool no_solution = true;
	for (double x = 1; x * x < R2; x++)
	{
		double y = R2 - x * x;
		y = sqrt(y);
		if (y < x) break;
		if (is_int(y))
		{
			no_solution = false;
			printf("%d %d\n", (int)x, (int)y);
		}
	}
	if (no_solution) printf("No Solution\n");
}

int main()
{
	solve();
	return 0;
}
