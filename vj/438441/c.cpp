#include <iostream>
#include <algorithm>
#include <cmath>

double x[4], y[4];
struct D {
    double d;
    int p, q;
} d[3];

double dis2(int i, int j)
{
    return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

bool cmp(const D &a, const D &b)
{
    return a.d < b.d;
}

int main()
{
    int T;
    std::cin >> T;
    int kase = 1;
    while (T--) {
        for (int i = 0; i < 4; i++)
            std::cin >> x[i] >> y[i];
        d[0] = D{dis2(0, 1), 0, 1};
        d[1] = D{dis2(0, 2), 0, 2};
        d[2] = D{dis2(1, 2), 1, 2};
        std::sort(d, d + 3, cmp);
        //std::cout << d[0].d << " " << d[1].d << " " << d[2].d << std::endl;
        double mx, my, r;
        if (d[0].d + d[1].d >= d[2].d) {
            //std::cout << "not obtuse triangle" << std::endl;
            mx = (x[0] + x[1] + x[2]) / 3.0;
            my = (y[0] + y[1] + y[2]) / 3.0;
            r = sqrt((mx - x[0]) * (mx - x[0]) + (my - y[0]) * (my - y[0]));
        } else {
            //std::cout << "obtuse triangle" << std::endl;
            mx = (x[d[2].p] + x[d[2].q]) / 2.0;
            my = (y[d[2].p] + y[d[2].q]) / 2.0;
            r = sqrt((mx - x[d[2].p]) * (mx - x[d[2].p]) + (my - y[d[2].p]) * (my - y[d[2].p]));
        }
        double r1 = sqrt((mx - x[3]) * (mx - x[3]) + (my - y[3]) * (my - y[3]));
        //std::cout << mx << " " << my << " " << r << " " << r1 << std::endl;
        std::cout << "Case #" << kase++ << ": ";
        if (r1 <= r)
            std::cout << "Danger";
        else
            std::cout << "Safe";
        std::cout << std::endl;
    }
    return 0;
}