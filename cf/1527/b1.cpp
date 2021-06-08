#include <cstdio>
#include <cstring>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[1010];
        scanf("%s", s);
        int zero = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') zero++;
        }
        if (zero % 2) {
           if (zero == 1) puts("BOB");
           else puts("ALICE");
        } else {
           puts("BOB");
        }
    }
}