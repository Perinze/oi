#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
const int bsiz = 320;

int n, m;
int a[maxn];
int num[maxn];
int bucket[maxn / bsiz + 5][bsiz];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		bucket[i / bsiz][i % bsiz] = a[i];
		num[i] = a[i];
	}
	sort(num, num + n);
	for (int i = 0; i < n / bsiz; i++)
		sort(bucket[i], bucket[i] + bsiz);
	
	while (m--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l--;
		// [l, r)

		int lb = -1, ub = n - 1;
		int md, x;
		while (lb + 1 < ub) {
			md = (lb + ub) >> 1;
			x = num[md];
			int tl = l, tr = r, c = 0;
			while (tl < tr && tl % bsiz) if (a[tl++] <= x) c++;
			while (tl < tr && tr % bsiz) if (a[--tr] <= x) c++;
			for (int b = tl / bsiz; b < tr / bsiz; b++) {
				c += upper_bound(bucket[b], bucket[b] + bsiz, x) - bucket[b];
				tl += bsiz;
			}
			if (c >= k) ub = md;
			else lb = md;
		}
		printf("%d\n", num[ub]);
	}
	return 0;
}