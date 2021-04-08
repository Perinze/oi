#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double v;
    scanf("%d%lf", &n, &v);
    int a[20], b[20];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    double c[20];
    double m = 10000000; int p;
    for (int i = 0; i < n; i++) {
        c[i] = 1.0 * b[i] / a[i];
        if (m > c[i])
            m = c[i], p = i;
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += m * a[i];
    printf("%f\n", min(sum, v));
    return 0;
}