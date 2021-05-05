#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
// [1, N][1, M]
int bit[maxn][maxn], n = 1010;
int bittmp[maxn][maxn];

void init()
{
    static bool inited;
    if (!inited) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                bittmp[i][j] = (i & -i) * (j & -j);
        inited = true;
    }
    memcpy(bit, bittmp, sizeof(bit));
}

int query(int i_, int j_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		for (int j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

inline int query(int i1, int j1, int i2, int j2)
{
    return query(i2, j2) - query(i1 - 1, j2) - query(i2, j1 - 1) + query(i1 - 1, j1 - 1);
}

int add(int i_, int j_, int x)
{
    if (x < 0)
        x = max(-query(i_, j_, i_, j_), x);
	for (int i = i_; i <= n; i += i & -i)
		for (int j = j_; j <= n; j += j & -j)
			bit[i][j] += x;
    return x;
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while (T--) {
        init();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", kase++);
        char cmd[2];
        int a, b, c, d, e;
        while (q--) {
            scanf("%s", cmd);
            if (!strcmp(cmd, "S")) {
                scanf("%d%d%d%d", &a, &b, &c, &d);
                a++, b++, c++, d++;
                if (a > c) swap(a, c);
                if (b > d) swap(b, d);
                printf("%d\n", query(a, b, c, d));
            } else if (!strcmp(cmd, "A")) {
                scanf("%d%d%d", &a, &b, &c);
                a++, b++;
                add(a, b, c);
            } else if (!strcmp(cmd, "D")) {
                scanf("%d%d%d", &a, &b, &c);
                a++, b++;
                add(a, b, -c);
            } else if (!strcmp(cmd, "M")) {
                scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
                a++, b++, c++, d++;
                int x = -add(a, b, -e);
                add(c, d, x);
            }
        }
    }
    return 0;
}