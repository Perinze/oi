#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXL 5000010

char pat[MAXL];
char str[MAXL];
int nxt[MAXL];
int l[MAXL];
int r[MAXL];

int plen, len;

void init()
{
    int k = -1;
    nxt[0] = -1;
    for (int i = 1; i < plen; i++) {
        while (k > -1 && pat[i] != pat[k + 1])
            k = nxt[k];
        if (pat[i] == pat[k + 1])
            k++;
        nxt[k] = k;
    }
}

inline void rm(int i)
{
    int b = l[i];
    int f = r[i];
    if (b >= 0) r[b] = f;
    l[f] = b;
    str[i] = '.';
}

void replace()
{
    int k = -1;
    for (int i = 0; i < len; i = r[i]) {
        if (str[i] == '.') continue;
        while (k > -1 && str[i] != pat[k + 1])
            k = nxt[k];
        if (str[i] == pat[k + 1])
            k++;
        if (k == plen - 1) {
            for (int t = 0; t < plen; t++) {
                rm(i);
                i = l[i];
            }
        }
    }
}

int main()
{
    while (~scanf("%s%s", pat, str)) {
        plen = strlen(pat);
        len = strlen(str);
        if (plen == 1) {
            for (int i = 0; i < len; i++)
                if (str[i] != pat[0])
                    putchar(str[i]);
            putchar('\n');
            continue;
        }
        memset(nxt, 0, sizeof(nxt));
        init();
        for (int i = 0; i < len; i++)
            l[i] = i - 1, r[i] = i + 1;
        replace();
        //puts(str);
        for (int i = 0; i < len; i = r[i])
            if (str[i] != '.')
                putchar(str[i]);
        putchar('\n');
    }
    return 0;
}