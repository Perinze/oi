#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int d[maxn];
int n;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        bool have_positive = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 0) have_positive = true;
        }
        /*
        if (!have_positive) {
            cout << n << endl;
            //cout << endl;
            continue;
        }
        */
        sort(a + 1, a + 1 + n);
        d[2] = a[2] - a[1];
        for (int i = 3; i <= n; i++)
            d[i] = min(d[i - 1], a[i] - a[i - 1]);
        for (int i = n; i > 0; i--) {
            if (d[i] >= a[i]) {
                cout << i << endl;
                break;
            }
            if (i == 1) cout << 1 << endl;
        }
    }
}