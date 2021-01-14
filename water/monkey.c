#include <stdio.h>

int next[1001];

int main()
{
    int n;
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        next[i] = i == n? 1: i + 1;
    }
    int crt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int one = crt, two = next[one], three = next[two];
        next[two] = next[three];
        //printf("delete %d\n", three);
        crt = next[two];
        //printf("to %d\n", crt);
    }
    printf("%d", crt);
    return 0;
}
