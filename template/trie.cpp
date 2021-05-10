int trie[maxn][26];
int sum[maxn];
int cnt;

void init()
{
    memset(trie, -1, sizeof(trie));
    cnt = 0;
}

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