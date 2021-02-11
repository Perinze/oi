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