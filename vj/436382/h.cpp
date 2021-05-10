#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5e5 + 10;
int trie[maxn][26];
int sum[maxn];
int vis[maxn];
int cnt = 0;
int P, Q;
char tmp[30];

void insert(char *s, int id)
{
    int crt = 0;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (trie[crt][x] == -1) {
            trie[crt][x] = ++cnt;
            //printf("%d[%c] -> %d\n", crt, x + 'a', cnt);
        }
        crt = trie[crt][x];
        if (vis[crt] != id)
            sum[crt]++;
        vis[crt] = id;
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

void add(char *s, int id)
{
    for (int i = 0; i < strlen(s); i++)
        insert(s + i, id);
}

int main()
{
    memset(trie, -1, sizeof(trie));
    scanf("%d", &P);
    for (int i = 1; i <= P; i++) {
        scanf("%s", tmp);
        add(tmp, i);
    }
    /*
    for (int i = 1; i <= cnt; i++)
        printf("sum[%d] = %d\n", i, sum[i]);
    */
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%s", tmp);
        printf("%d\n", search(tmp));
    }
    return 0;
}