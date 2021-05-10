#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            int m = n / 2;
            int r = sqrt(m);
            if (r * r == m) {
                puts("YES");
                continue;
            }
        }
        if (n % 4 == 0) {
            int m = n / 4;
            int r = sqrt(m);
            if (r * r == m) {
                puts("YES");
                continue;
            }
        }
        puts("NO");
    }
    return 0;
}