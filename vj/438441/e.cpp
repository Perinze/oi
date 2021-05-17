#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T;
    int kase = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int crt, tmp;
        cin >> tmp;
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            cin >> crt;
            if (crt != tmp + 1) ans = i;
            tmp = crt;
        }
        cout << "Case #" << kase++ << ": " << ans << endl;
    }
    return 0;
}