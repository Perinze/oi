#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int ans = -1, m, crt, lst = -1;
        while (n--)
        {
            scanf("%d", &crt);
            if (lst != crt) m = 0;
            m++;
            ans = max(ans, m);
            lst = crt;
        }
        printf("%d\n", ans);
    }
    return 0;
}