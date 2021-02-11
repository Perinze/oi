#include <cstdio>
#include <cstring>

char t[200000], p[200000];
int tlen, plen;
int a[200000];
bool del[200000];

bool C(int x)
{
    memset(del, 0, sizeof(del));
    for (int i = 0; i < x; i++)
        del[a[i]] = true;
    int cnt = 0;
    for (int i = 0; i < tlen; i++) {
        if (del[i])
            continue;
        if (p[cnt] == t[i])
            cnt++;
        if (cnt == plen)
            return true;
    }
    return false;
}

int main()
{
    scanf("%s", t);
    scanf("%s", p);
    tlen = strlen(t);
    plen = strlen(p);
    for (int i = 0; i < tlen; i++) {
        scanf("%d", a + i);
        a[i] -= 1;
    }
    int l = 0, r = tlen;
    int ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (C(mid)) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}