#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, C;
        cin >> N >> C;
        cout << "Case " << t << ": ";
        if (N == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int T1 = C / N / 2;
        int T2 = T1 + 1;
        int ans1 = T1 * (C - T1 * N);
        int ans2 = T2 * (C - T2 * N);
        cout << (ans1 >= ans2? T1: T2) << endl;
    }
    return 0;
}