#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int n;
int a[maxn];
int bit[maxn];

void add(int i_, int x)
{
    for (int i = i_; i > 0; i -= i & -i)
        bit[i] += x;
}

int query(int i_)
{
    int sum = 0;
    for (int i = i_; i <= n; i += i & -i)
        sum += bit[i];
    return sum;
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += query(a[i]);
            add(a[i], 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}