#include <cstdio>
#include <cctype>
#include <algorithm>

const int MAXN = 200010;
int n, m;
char s[MAXN], t[MAXN];
int l[MAXN], r[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    int p = -1;
    for (int i = 0; i < m; ) {
        if (s[++p] == t[i]) l[i++] = p;
    }
    p = n;
    for (int i = m - 1; i >= 0; ) {
        if (s[--p] == t[i]) r[i--] = p;
    }
    int ans = -1;
    for (int i = 0; i < m - 1; i++) {
        ans = std::max(r[i + 1] - l[i], ans);
    }
    printf("%d\n", ans);
    return 0;
}