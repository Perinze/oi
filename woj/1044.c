#include <stdio.h>
#include <stdbool.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N;
		scanf("%d", &N);

		bool p0ex = false;
		int n_best;
		double r_best = 0.0;
		for (int n = 1; n <= N; n++)
		{
			int w, p;

			scanf("%d %d", &w, &p);
			if ((!p0ex) && (!p))
			{
				p0ex = true;
				r_best = 0.0;
			}
			if (p0ex)
			{
				if (p) continue;
				if (w > r_best)
				{
					n_best = n;
					r_best = w;
				}
			}
			else
			{
				double r_cur = (double)w / (double)p;
				if (r_cur > r_best)
				{
					n_best = n;
					r_best = r_cur;
				}
			}
		}
		printf("%d\n", n_best);
	}
	return 0;
}
