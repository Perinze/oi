#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[105];
int b[105];
int t[105];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", a + i, b + i);
        for (int i = 1; i <= n; i++)
            scanf("%d", t + i);
        int c = 0;
        c += a[1] + t[1];
        //printf("%d\n", c);
        for (int i = 1; i < n; i++) {
            c = max(a[i], c);
            c = max(b[i], c + (b[i] - a[i] + 1) / 2);
            c += a[i + 1] - b[i] + t[i + 1];
        }
        printf("%d\n", c);
    }
    return 0;
}