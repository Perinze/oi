#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXL 5000010

char pat[MAXL];
char str[MAXL];
int nxt[MAXL];
int jump[MAXL];

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

void replace()
{
    int k = -1;
    for (int i = 0; i < len; i++) {
        if (jump[i]) i = jump[i];
        if (str[i] == '.') continue;
        while (k > -1 && str[i] != pat[k + 1])
            k = nxt[k];
        if (str[i] == pat[k + 1])
            k++;
        if (k == plen - 1) {
            for (int t = 0; t < plen; t++) {
                while (str[i] == '.') i--;
                if (i < 0) {
                    i = 0;break;
                }
                str[i] = '.';
                i--;
            }
            jump[i] = i + plen + 1;
            for (int t = 0; t < plen - 1; t++) {
                while (str[i] == '.') i--;
                if (i < 0) {
                    i = 0; break;
                }
                i--;
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
        replace();
        //puts(str);
        for (int i = 0; i < len; i++)
            if (str[i] != '.')
                putchar(str[i]);
        putchar('\n');
    }
    return 0;
}