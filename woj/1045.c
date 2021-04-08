#include <stdio.h>

float min(float, float);

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		float ex, tc, eq, a;
		scanf("%f %f %f %f", &ex, &tc, &eq, &a);
		ex += .1 * a; ex = min(100.0, ex); ex /= 100.0;
		tc += .1 * a; tc = min(100.0, tc); tc /= 100.0;
		eq += .1 * a; eq = min(100.0, eq); eq /= 100.0;
		printf("%.3f %.3f %.3f\n", ex, tc, eq);
	}
	return 0;
}

float min(float a, float b)
{
	return a<b?a:b;
}
