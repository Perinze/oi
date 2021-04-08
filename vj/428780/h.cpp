#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define debug
#define maxn 2100000
#define flen 21
int n;
int pre[maxn];
int trie[maxn][2];
int map[maxn];
int cnt = 0;
char tmp[flen];

void insert(char *seq, int len, int ite)
{
    int crt = 0;
    for (int i = 0; i < len; i++) {
        int x = seq[i];
        if (!trie[crt][x])
            trie[crt][x] = ++cnt;
        crt = trie[crt][x];
    }
    map[crt] = ite;
}

int find(char *seq, int len)
{
    int crt = 0;
    for (int i = 0; i < len; i++) {
        int x = seq[i];
        if (trie[crt][x ^ 1])
            crt = trie[crt][x ^ 1];
        else if (trie[crt][x])
            crt = trie[crt][x];
        else
            return -1;
    }
    return map[crt];
}

void i2s(int x, char *s, int len)
{
    for (int i = 0; i < len; i++) {
        s[i] = x % 2;
        x /= 2;
    }
}

int main()
{
    memset(map, -1, sizeof(map));
    scanf("%d", &n);
    int l, r, ans = 0;
    for (int i = 1; i <= n; i++) {
        #ifdef debug
        printf("in loop %d:\n", i);
        #endif

        int x;
        scanf("%d", &x);
        pre[i] = pre[i - 1] ^ x;

        #ifdef debug
        printf("\tnumber is %d, prefix xor is %d\n", x, pre[i]);
        #endif

        x = pre[i];
        i2s(x, tmp, flen);
        reverse(tmp, tmp + flen);

        #ifdef debug
        printf("\treversed sequence: ");
        for (int i = 0; i < flen; i++) printf("%d", tmp[i]);
        putchar('\n');
        #endif
        
        int y = find(tmp, flen);
        #ifdef debug
        printf("\tfind(tmp) last node index: %d\n", y);
        #endif
        if (y == -1) {
            if (x > ans)
                l = 1, r = i, ans = x;
            insert(tmp, flen, i);
            continue;
        }

        #ifdef debug
        printf("\tfind(tmp): %d\n", y);
        printf("\tat which the prefix xor is %d\n", pre[y]);
        i2s(pre[y], tmp, flen);
        reverse(tmp, tmp + flen);
        printf("\treversed sequence: ");
        for (int i = 0; i < flen; i++) printf("%d", tmp[i]);
        putchar('\n');
        #endif
        
        int res = pre[x] ^ pre[y];
        if (y != -1 && res > ans)
            l = y + 1, r = i, ans = res;
        insert(tmp, flen, i);
    }
    printf("%d %d %d\n", l, r, ans);
    return 0;
}