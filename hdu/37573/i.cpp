#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n, m;
int bit[maxn][maxn][maxn];

void add(int i_, int j_, int k_)
{
    for (int i = i_; i <= n; i += i & -i)
        for (int j = j_; j <= n; j += j & -j)
            for (int k = k_; k <= n; k += k & -k)
                bit[i][j][k] += 1;
}

void add(int i1, int j1, int k1, int i2, int j2, int k2)
{
    add(i2 + 1, j2 + 1, k2 + 1);
    add(i1, j2 + 1, k2 + 1);
    add(i2 + 1, j1, k2 + 1);
    add(i2 + 1, j2 + 1, k1);
    add(i1, j1, k2 + 1);
    add(i1, j2 + 1, k1);
    add(i2 + 1, j1, k1);
    add(i1, j1, k1);
}

int sum(int i_, int j_, int k_)
{
    int s = 0;
    for (int i = i_; i > 0; i -= i & -i)
        for (int j = j_; j > 0; j -= j & -j)
            for (int k = k_; k > 0; k -= k & -k)
                s += bit[i][j][k];
    return s;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        memset(bit, 0, sizeof(bit));
        int cmd;
        for (int i = 0; i < m; i++) {
            scanf("%d", &cmd);
            if (cmd == 1) {
                int x1, y1, z1, x2, y2, z2;
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                add(x1, y1, z1, x2, y2, z2);
            } else {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                printf("%d\n", sum(x, y, z) & 1);
            }
        }
    }
    return 0;
}