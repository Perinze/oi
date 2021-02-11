#include <cstdio>

int a[100000], b[100000];
int n, p;

bool C(double t)
{
    double w = p * t;
    for (int i = 0; i < n; i++) {
        if (a[i] * t > b[i])
            w -= a[i] * t - b[i];
        if (w < 0)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &p);
    long long load = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        scanf("%d", b + i);
        load += a[i];
    }
    if (load <= p) {
        printf("%d\n", -1);
    } else {
        double l = 0;
        double r = 1e10;
        double ans;
        while (r - l > 1e-6) {
            double mid = (l + r) / 2.0;
            if (C(mid)) {
                l = mid;
                ans = mid;
            } else
                r = mid;
        }
        printf("%f\n", ans);
    }
    return 0;
}