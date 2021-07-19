#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
int n;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) cout << 1 << endl;
        else if (n == 2) cout << 3 << endl;
        else {
            for (int i = 0; i + 2 < n; i++) {
                if (a[i + 1] > a[i] && a[i + 2] < a[])
            }
        }
    }
}