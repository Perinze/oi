#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 10) continue;
        res += x - 10;
    }
    cout << res << endl;
    return 0;
}