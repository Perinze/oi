#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int maxn = 110;
int n;

int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

struct P {
    double x, y;
    P() {}
    P(double x, double y): x(x), y(y) {}
    P operator -(const P &s) const
    {
        return P(x - s.x, y - s.y);
    }
    double operator ^(const P &s) const
    {
        return x * s.y - y * s.x;
    }
    double operator *(const P &s) const
    {
        return x * s.x + y * s.y;
    }
} ps[maxn * 2];

bool intersect(P a1, P a2, P b1, P b2)
{
    return sgn((b1 - a1) ^ (b1 - a2)) * sgn((b2 - a1) ^ (b2 - a2)) <= 0;
}

double dist(P a, P b)
{
    return sqrt((b - a) * (b - a));
}

bool test(P s, P t)
{
    if (sgn(dist(s, t)) == 0) return false;
    for (int i = 0; i < n; i++)
        if (!intersect(s, t, ps[i * 2], ps[i * 2 + 1]))
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        double x, y;
        for (int i = 0; i < 2 * n; i++) {
            cin >> x >> y;
            ps[i] = P(x, y);
        }
        bool found = false;
        for (int i = 0; !found && i < 2 * n; i++) {
            for (int j = i + 1; !found && j < 2 * n; j++) {
                if (test(ps[i], ps[j])) {
                    found = true;
                    break;
                }
            }
        }
        if (found) cout << "Yes!" << endl;
        else cout << "No!" << endl;
    }
    return 0;
}