#include <cstdio>
#include <cctype>
#include <algorithm>

namespace io {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s= 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') s = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        return x * s;
    }
}

struct cell {
    int x, y, w;
} c[50010];
int m, n, q;

bool cmp1(const cell &a, const cell &b)
{
    return a.x < b.x;
}

bool cmp2(const cell &a, const cell &b)
{
    return a.y < b.y;
}

int main()
{
    int T = io::read<int>();
    for (int cas = 1; cas <= T; cas++) {
        m = io::read<int>();
        n = io::read<int>();
        q = io::read<int>();
        int sum = 0;
        for (int i = 0; i < q; i++) {
            c[i].x = io::read<int>();
            c[i].y = io::read<int>();
            c[i].w = io::read<int>();
            sum += c[i].w;
        }
        printf("Case %d: ", cas);
        sum >>= 1;
        int s = 0;
        std::sort(c, c + q, cmp1);
        for (int i = 0; i < q; i++) {
            s += c[i].w;
            if (s > sum) {
                printf("%d ", c[i].x);
                break;
            }
        }
        s = 0;
        std::sort(c, c + q, cmp2);
        for (int i = 0; i < q; i++) {
            s += c[i].w;
            if (s > sum) {
                printf("%d\n", c[i].y);
                break;
            }
        }
    }
    return 0;
}