#include <cstdio>
#include <cstring>

#define MAXP 10010
#define MAXS 1000010

char pat[MAXP];
char str[MAXS];

void init(char *pat, int *nxt)
{
	int len = strlen(pat);
	int k = -1;
	nxt[0] = -1;
	for (int i = 1; i < len; i++) {
		while (k > -1 && pat[i] != pat[k + 1])
			k = nxt[k];
		if (pat[i] == pat[k + 1])
			k++;
		nxt[i] = k;
	}
}

int kmp(char *str, char *pat) // pattern should be len + 1
{
	int plen = strlen(pat);
	int nxt[plen + 1];
	init(pat, nxt);
	int len = strlen(str);
	int k = -1;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		while (k > -1 && str[i] != pat[k + 1])
			k = nxt[k];
		if (str[i] == pat[k + 1])
			k++;
		if (k == plen - 1)
			ans++;
	}
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", pat);
        scanf("%s", str);
        printf("%d\n", kmp(str, pat));
    }
    return 0;
}