#include <cstdio>

int main()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    // k <= a + b - 2
    if (k == 0) {
        puts("Yes");
        for (int i = 0; i < b; i++) putchar('1');
        for (int i = 0; i < a; i++) putchar('0');
        putchar('\n');
        for (int i = 0; i < b; i++) putchar('1');
        for (int i = 0; i < a; i++) putchar('0');
        putchar('\n');
    } else {
        if (b == 1) goto No;
        if (k > a + b - 2) goto No;
        
        puts("Yes");
        putchar('1');
        putchar('1');
        for (int i = 0; i < k; i++) putchar('0');
        for (int i = 0; i < b - 2; i++) putchar('1');
        for (int i = 0; i < a - k; i++) putchar('0');
        putchar('\n');
        putchar('1');
        for (int i = 0; i < k; i++) putchar('0');
        putchar('1');
        for (int i = 0; i < b - 2; i++) putchar('1');
        for (int i = 0; i < a - k; i++) putchar('0');
        putchar('\n');
    }

    return 0;

    No:
    puts("No");
    return 0;
}