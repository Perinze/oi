#include <cstdio>

int n;
char s[1010];
int cnt;
int zero, one;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        cnt = 0;
        zero = one = 0;
        scanf("%d", &n);
        char c;
        while ((c = getchar()) != '0' && c != '1');
        s[++cnt] = c - '0';
        if (c == '0') zero++;
        else one++;
        while ((c = getchar()) == '0' || c == '1') {
            s[++cnt] = c - '0';
            if (c == '0') zero++;
            else one++;
        }
        if (zero % 2) {
           if (n == 1) puts("BOB");
           else puts("ALICE");
        } else {
           puts("BOB");
        }
    }
    return 0;
}