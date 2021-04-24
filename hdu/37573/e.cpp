#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int n, m, x, y;
int bit[maxn][maxn];

void add(int i_, int j_, int x)
{
    for (int i = i_; i <= n; i += i & -i)
        for (int j = j_; j <= m; j += j & -j)
            bit[i][j] += x;
}

int query(int i_, int j_)
{
    int sum = 0;
    for (int i = i_; i > 0; i -= i & -i)
        for (int j = j_; j > 0; j -= j & -j)
            sum += bit[i][j];
    return sum;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int x;
                scanf("%d", &x);
                add(i, j, x);
            }
        int ans = -1;
        for (int i = 1; i <= n - y + 1; i++)
            for (int j = 1; j <= m - x + 1; j++)
                ans = max(ans, query(i + y - 1, j + x - 1) - query(i + y - 1, j - 1) - query(i - 1, j + x - 1) + query(i - 1, j - 1));
        printf("%d\n", ans);
    }
    return 0;
}