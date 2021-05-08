#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
int n;
string str;
ll a[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> str;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '*')
                a[cnt++] = i;
        ll sum = 0, dt;
        if (cnt % 2) { // even
            ll mid = a[cnt / 2];
            for (int i = 0; i < cnt; i++)
                sum += a[i] > mid ? a[i] - mid : mid - a[i];
            dt = cnt / 2 + 1;
            dt = dt * (dt - 1) / 2;
            dt *= 2;
            cout << sum - dt << endl;
        } else { // odd
            ll mid = a[cnt / 2];
            for (int i = 0; i < cnt; i++)
                sum += a[i] > mid ? a[i] - mid : mid - a[i];
            dt = (cnt / 2) * (cnt / 2 - 1) / 2 + (cnt / 2 + 1) * (cnt / 2) / 2;
            cout << sum - dt << endl;
        }
    }
    return 0;
    // even
    // f(x) = x * (x - 1) / 2
    // g(x) = 2 * f(x / 2 + 1)
}