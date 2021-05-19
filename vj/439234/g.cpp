#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
const double eps = 1e-8;
int n;

struct P {
    double x, y;
    P (double x = 0, double y = 0): x(x), y(y) {}
    P operator-(const P &s) const {
        return P(x - s.x, y - s.y);
    }
} segs[maxn * 2];

inline int xmul(P p, P q)
{
    return p.x * q.y - p.y * q.x;
}

inline bool cross(P s, P t, P p, P q)
{
    if (xmul(p - s, p - t) * xmul(q - s, q - t) <= 0.0) return true;
    return false;
}

bool equal(double x, double y)
{
    if (fabs(x - y) < eps) return true;
    return false;
}

bool equal(P p, P q)
{
    return equal(p.x, q.x) && equal(p.y, q.y);
}

bool test(P s, P t)
{
    for (int i = 0; i < n; i++) {
        P p = segs[i * 2], q = segs[i * 2 + 1];
        if (!cross(s, t, p, q)) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        double xa, ya, xb, yb;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
            segs[i * 2] = {xa, ya};
            segs[i * 2 + 1] = {xb, yb};
        }
        bool found = false;
        for (int i = 0; !found && i < 2 * n; i++) {
            for (int j = i + 1; !found && j < 2 * n; j++) {
                if (equal(segs[i], segs[j])) continue;
                if (test(segs[i], segs[j]))
                    found = true;
            }
        }
        if (found) puts("Yes!");
        else puts("No!");
    }
    return 0;
}