#include <iostream>
using namespace std;

int Joseph(int n, int k)
{
    if (n == 1) return 0;
    return (Joseph(n - 1, k) + k) % n;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;
        cout << "Case " << t << ": ";
        cout << Joseph(n, k) + 1 << endl;
    }
    return 0;
}