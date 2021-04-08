#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 1000010;
int trie[MAXN][26];
int sum[MAXN];
int cnt = 0;

void insert(char *s)
{
    int crt = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[crt][x] == -1)
            trie[crt][x] = ++cnt;
        crt = trie[crt][x];
        sum[crt]++;
    }
}

int search(char *s)
{
    int crt = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[crt][x] == -1)
            return 0;
        crt = trie[crt][x];
    }
    return sum[crt];
}

int main()
{
    memset(trie, -1, sizeof(trie));
    char buf[12];
    for (;;) {
        fgets(buf, 12, stdin);
        buf[strlen(buf) - 1] = 0;
        if (!buf[0]) {
            break;
        }
        insert(buf);
    }
    while (fgets(buf, 12, stdin)) {
        if (strlen(buf) == 1) break;
        buf[strlen(buf) - 1] = 0;
        printf("%d\n", search(buf));
    }
    return 0;
}