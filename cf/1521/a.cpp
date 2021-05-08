#include <iostream>
using namespace std;

typedef long long ll;
ll a, b;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (b == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        bool go = true;
        for (ll k = 1; go; k++)
            for (ll i = 1; i < k * b; i++) // i * a, (k * b - i) * a, k * a * b
                if (i != k * b - i && i != k * b && k * b - i != k * b && i % b && (k * b - i) % b) {
                    cout << i * a << ' ' << (k * b - i) * a << ' ' << k * a * b << endl;
                    go = false;
                    break;
                }

    }
    return 0;
}