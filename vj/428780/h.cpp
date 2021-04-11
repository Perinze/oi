#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100000
#define flen 21
int n;
int pre[maxn];
int trie[1 << (flen + 1)][2];
int map[maxn];
int cnt;
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
        if (trie[crt][x ^ 1]) {
            crt = trie[crt][x ^ 1];
        } else if (trie[crt][x]) {
            crt = trie[crt][x];
        } else {
            return -1;
        }
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
    while (~scanf("%d", &n)) {
        cnt = 0;
        memset(trie, 0, sizeof(trie));
        memset(map, -1, sizeof(map));
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            pre[i] = pre[i - 1] ^ x;
        }
        int l = 1, r = 1, ans = pre[1];
        for (int i = 1; i <= n; i++) {
            i2s(pre[i], tmp, flen);
            reverse(tmp, tmp + flen);
            insert(tmp, flen, i);
            int y = find(tmp, flen);
            int res = pre[y] ^ pre[i];
            if (res > ans) ans = res, l = y + 1, r = i;
        }
        printf("%d %d %d\n", ans, l, r);
    }
    return 0;
}