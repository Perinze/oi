#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXL 5000010
char pat[MAXL];
char str[MAXL];
int nxt[MAXL];
int fwd[MAXL];
int bak[MAXL];

int plen, len;

void init()
{
    nxt[0] = -1;
    int k = -1;
    for (int i = 1; i < plen; i++) {
        while (k > -1 && pat[i] != pat[k + 1])
            k = nxt[k];
        if (pat[i] == pat[k + 1])
            k++;
        nxt[i] = k;
    }
}

void replace()
{
    init();
    for (int i = 0; i < len; i++)
        bak[i] = i - 1, fwd[i] = i + 1;
    int k = -1;
    for (int i = 0; str[i]; i = fwd[i]) {
        //printf("%d -> %d:%c -> %d\n", bak[i], i, str[i], fwd[i]);
        while (k > -1 && str[i] != pat[k + 1])
            k = nxt[k];
        if (str[i] == pat[k + 1]) {
            k++;
            if (k == plen - 1)
                for (int t = 0; t < plen; t++) {
                    int f = fwd[i], b = bak[i];
                    if (f >= 0) bak[f] = b;
                    if (b >= 0) fwd[b] = f;
                    str[i] = '.';
                    i = max(b, 0);
                }
        }
    }
}

int main()
{
    while (~scanf("%s%s", pat, str)) {
        memset(nxt, 0, sizeof(nxt));
        plen = strlen(pat);
        len = strlen(str);
        if (len < plen) {
            puts(str);
            continue;
        }
        if (plen == 1) {
            char c = pat[0];
            for (int i = 0; i < len; i++)
                if (str[i] != c)
                    putchar(str[i]);
            putchar('\n');
            continue;
        }
        replace();
        for (int i = 0; str[i]; i = fwd[i])
            if (str[i] != '.')
                putchar(str[i]);
        putchar('\n');
    }
    return 0;
}