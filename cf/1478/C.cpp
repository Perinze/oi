#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[100000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);

		bool fail = false;
		map<ll, int> t;
		for (int i = 0; i < 2 * n; i++)
		{
			ll d;
			scanf("%lld", &d);
			t[d]++;
			if (d % 2) fail = true;
		}
		if (fail)
		{
			puts("NO");
			continue;
		}
// a, -a, b, -b, c, -c
// 2a + 2b + 2c
// 4b + 2c
// 6c

		for (auto ite = t.begin(); ite != t.end(); ite++)
		{
			if (ite->second != 2)
			{
				fail = true;
				break;
			}
		}
		if (fail)
		{
			puts("NO");
			continue;
		}

		int p = 0;
		ll sum = 0;
		for (auto ite = t.rbegin(); ite != t.rend(); ite++)
		{
			ll d = ite->first / 2;
			if ((d - sum) % (n - p))
			{
				fail = true;
				break;
			}
			a[p] = (d - sum) / (n - p);
			sum += a[p];

			if (a[p] <= 0)
			{
				fail = true;
				break;
			}
			p++;
		}
		if (fail)
		{
			puts("NO");
			continue;
		}
		sort(a, a + n);
		ll lst = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] == lst)
			{
				fail = true;
				break;
			}
			lst = a[i];
		}
		if (fail)
		{
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
