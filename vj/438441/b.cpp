#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 310;

int x[maxn], y[maxn], vx[maxn], vy[maxn];
int n;

inline double getx(int i, double t)
{
    return x[i] + vx[i] * t;
}

inline double gety(int i, double t)
{
    return y[i] + vy[i] * t;
}

double dis(int i, int j, double t)
{
    double dx = getx(i, t) - getx(j, t);
    double dy = gety(i, t) - gety(j, t);
    return sqrt(dx * dx + dy * dy);
}

double dissum(double t)
{
    double s = 0.0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            s += dis(i, j, t);
        }
    }
    return s;
}

int main()
{
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d%d", x + i, y + i, vx + i, vy + i);
        double l = 0.0, r = (double)1e9;
        while (r - l >= 0.0001) {
            double midl = l + (r - l) / 3.0;
            double midr = r - (r - l) / 3.0;
            if (dissum(midl) < dissum(midr)) {
                r = midr;
            } else {
                l = midl;
            }
        }
        printf("Case #%d: %.2f %.2f\n", kase++, l, dissum(l));
    }
    return 0;
}