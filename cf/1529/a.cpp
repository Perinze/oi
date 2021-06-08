#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[110];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = 0x3f3f3f3f;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < mx) {
                mx = a[i], cnt = 1;
            } else if (a[i] == mx) {
                cnt++;
            }
        }
        cout << n - cnt << endl;
    }
    return 0;
}