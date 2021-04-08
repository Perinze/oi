#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        // 
        double v1, v2, v3, a1, a2;
        cin >> v1 >> v2 >> v3 >> a1 >> a2;
        double t1 = v1 / a1;
        double t2 = v2 / a2;
        double d = 0.5 * (v1 * t1 + v2 * t2);
        double s = max(t1, t2) * v3;
        cout << setprecision(9);
        cout << fixed;
        cout << "Case " << cas << ": " << d << " " << s << endl;
    }
    return 0;
}