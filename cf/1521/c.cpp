#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int p1;
int p[maxn];
int n;

int query(int t, int i, int j, int x)
{
    printf("? %d %d %d %d\n", t, i, j, x);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == -1) exit(0);
    return res;
}

bool det(int i)
{
    // 0 found
    // 1 not found
    int a = query(2, i, i + 1, 1);
    if (a == 1) {
        p1 = i;
        return 0;
    } else if (a == 2) {
        if (query(2, i + 1, i, 1) == 1) {
            p1 = i + 1;
            return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        p1 = 0;
        scanf("%d", &n);
        for (int i = 1; i < n && det(i); i += 2);
        if (!p1 && n % 2) p1 = n;
        p[p1] = 1;
        for (int i = 1; i <= n; i++) {
            if (i == p1) continue;
            p[i] = query(1, p1, i, n - 1);
        }
        printf("!");
        for (int i = 1; i <= n; i++)
            printf(" %d", p[i]);
        puts("");
        fflush(stdout);
    }
    return 0;
}