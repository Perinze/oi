#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50010;
int n;
double L, R;
int bit[maxn];

struct Line {
    double ly, ry;
    int id;
} line[maxn];
int len;

bool cmp1(const Line &l1, const Line &l2)
{
    if (l1.ly == l2.ly) return l1.ry < l2.ry;
    return l1.ly < l2.ly;
}

bool cmp2(const Line &l1, const Line &l2)
{
    if (l1.ry == l2.ry) return l1.ly < l2.ly;
    return l1.ry < l2.ry;
}

void add(int i, int x)
{
    for (; i <= n; i += i & -i)
        bit[i] += x;
}

int query(int i)
{
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(bit, 0, sizeof(bit));
        len = 0;
        scanf("%lf%lf", &L, &R);
        int vtc = 0;
        for (int i = 1; i <= n; i++) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            if (x1 == x2) {
                if (x1 > L && x1 < R)
                    vtc++;
                continue;
            }
            double k = (y1 - y2) / (x1 - x2);
            double b = y1 - k * x1;
            line[++len] = Line{k * L + b, k * R + b};
        }
        sort(line + 1, line + 1 + len, cmp1);
        for (int i = 1; i <= len; i++)
            line[i].id = i;
        sort(line + 1, line + 1 + len, cmp2);
        int ans = len * vtc;
        for (int i = len; i > 0; i--) {
            ans += query(line[i].id - 1);
            add(line[i].id, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}