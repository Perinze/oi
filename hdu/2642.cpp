#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int n = 1010;
// [1, N]
int bit[maxn][maxn];
bool bright[maxn][maxn];

int sum(int a, int b)
{
	int s = 0;
    for (int i = a; i > 0; i -= (i & -i)) {
        for (int j = b; j > 0; j -= (j & -j)) {
            s += bit[i][j];
        }
    }
	return s;
}

void add(int a, int b, int x)
{
    for (int i = a; i < n; i += (i & -i)) {
        for (int j = b; j < n; j += (j & -j)) {
            bit[i][j] += x;
        }
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    char tmp[2];
    char cmd;
    while (m--) {
        scanf("%s", tmp);
        cmd = tmp[0];
        int a, b, c, d;
        switch (cmd) {
            case 'B':
                scanf("%d%d", &a, &b);
                a++, b++;
                if (!bright[a][b])
                    add(a, b, 1);
                bright[a][b] = true;
                break;
            case 'D':
                scanf("%d%d", &a, &b);
                a++, b++;
                if (bright[a][b])
                    add(a, b, -1);
                bright[a][b] = false;
                break;
            case 'Q':
                scanf("%d%d%d%d", &a, &b, &c, &d);
                a++, b++, c++, d++;
                if (a > b) swap(a, b);
                if (c > d) swap(c, d);
                printf("%d\n", sum(b, d) - sum(a - 1, d) - sum(b, c - 1) + sum(a - 1, c - 1));
                break;
        }
    }
    return 0;
}