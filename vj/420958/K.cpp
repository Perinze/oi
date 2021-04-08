<<<<<<< HEAD
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	int n;
	double k;
	cin >> n >> k;
	double a[10010];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	double l = a[0], r = a[n - 1];
	while (r - l >= 1e-6)
	{
		double mid = (r + l) / 2.0;
		double sum1 = 0.0, sum2 = 0.0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < mid) sum1 += mid - a[i];
			if (a[i] > mid) sum2 += a[i] - mid;
		}
		if (sum2 * (100.0 - k) / 100.0 > sum1) l = mid;
		else r = mid;
	}
	cout << l << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
=======
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int k;
    scanf("%d%d", &n, &k);
    int a[10000];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    double l = a[0], r = a[n - 1];
    while (r - l >= 1e-6)
    {
        double mid = (l + r) / 2.0;
        double sl = 0.0, sr = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mid)
                sl += mid - a[i];
            if (a[i] > mid)
                sr += a[i] - mid;
        }
        if (sl > sr * (100 - k) / 100.0)
            r = mid;
        else
            l = mid;
    }
    printf("%.9f\n", l);
    return 0;
}
>>>>>>> 451f61128d5e1a415065dc1de7aa6990da766e13
