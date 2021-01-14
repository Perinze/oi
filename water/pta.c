#include <stdio.h>
#define MAXN 10
#define each(i, l, r) for (int i = l; i < r; i++)

double fact( int n )
{
    double ans = 1.0;
    for (int i = 2; i <= n; i++) ans *= (double)i;
    return ans;
}

double factsum( int n )
{
    if (n == 0) return .0;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += fact(n);
    }
    return ans;
}

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

    return 0;
}
