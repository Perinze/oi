#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    while (cin >> n && n)
    {
        ll x = 1, y = 1;
        while (y < n)
        {
            x += y;
            swap(x, y);
        }
        if (y == n) cout << "Second win" << endl;
        else cout << "First win" << endl;
    }
    return 0;
}