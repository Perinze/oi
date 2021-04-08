#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10000010

int a[MAXN];
int trie[MAXN][2];
int n, m;
int cnt;
int maxbit;
int mask;

inline int bits(int x)
{
    int res = 0;
    while (x) {
        x >>= 1;
        res++;
    }
    return res;
}

void insert(int x, int bits)
{
    int crt = 0;
    for (int sh = bits - 1; sh >= 0; sh--) {
        int y = (x >> sh) & 1;
        if (!trie[crt][y])
            trie[crt][y] = cnt++;
        crt = trie[crt][y];
    }
}

int search(int x, int bits)
{
    int crt = 0;
    int ans = 0;
    for (int sh = bits - 1; sh >= 0; sh--) {
        int y = (x >> sh) & 1;
        if (trie[crt][!y]) {
            ans |= (!y) << sh;
            crt = trie[crt][!y];
        } else if (trie[crt][y]) {
            ans |= y << sh;
            crt = trie[crt][y];
        }
    }
    return ans;
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        maxbit = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            a[i] = x;
            maxbit = max(maxbit, bits(x));
        }
        mask = (1 << maxbit) - 1;
        memset(trie, 0, sizeof(trie));
        cnt = 1;
        for (int i = 0; i < n; i++)
            insert(a[i], maxbit);
        //printf("%d\n", maxbit);
        printf("Case #%d:\n", cas++);
        while (m--) {
            int x;
            scanf("%d", &x);
            x &= mask;
            printf("%d\n", search(x, maxbit));
        }
    }
    return 0;
}