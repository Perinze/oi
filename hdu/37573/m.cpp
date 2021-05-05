#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5010;
int a[maxn];
int bit[maxn];
int n;
int ans;

void add(int i, int x)
{
    for (; i <= n; i += i & -i)
        bit[i] += x;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

void rotate()
{
    int x = a[1];
    for (int i = 1; i < n; i++) {
        a[i] = a[i + 1];
        if (a[i] < x) ans -= 1;
        else if (a[i] > x) ans += 1;
    }
    a[n] = x;
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(bit, 0, sizeof(bit));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            a[i] += 1;
            add(a[i], 1);
            ans += i - query(a[i]);
        }
        int res = ans;
        for (int i = 1; i <= n - 1; i++) {
            rotate();
            res = min(ans, res);
        }
        printf("%d\n", res);
    }
    return 0;
}