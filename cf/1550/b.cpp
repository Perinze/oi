#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        char tmp[200];
        cin >> tmp;
        if (b >= 0) {
            cout << a * n + b * n << endl;
        } else {
            int x = 0;
            int start = tmp[0] - '0';
            int other = 1 - start;
            int crt, lst = start;
            int len = strlen(tmp);
            for (int i = 1; i < len; i++) {
                crt = tmp[i] - '0';
                if (lst == start && crt == other) {
                    x++;
                }
                lst = crt;
            }
            x++;
            //cout << "x = " << x << endl;
            cout << a * n + b * x << endl;
        }
    }
}