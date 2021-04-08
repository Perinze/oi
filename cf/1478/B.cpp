#include <iostream>
using namespace std;

bool dp[10][91];

int main()
{
    for (int d = 1; d <= 9; d++)
    {
        for (int i = 1; i < 10; i++)
        {
            dp[d][d * i] = true;
        }
    }
    for (int d = 1; d <= 9; d++)
    {
        for (int i = 1; i <= d; i++)
        {
            int n = i * 10 + d;
            dp[d][n] = true;
            for (int j = 1; j + n <= d * 10; j++)
            {
                if (dp[d][j]) dp[d][j + n] = true;
            }
        }
    }

    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int q, d;
        cin >> q >> d;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            if (x >= d * 10) cout << "YES" << endl;
            else cout << (dp[d][x]? "YES": "NO") << endl;
        }
    }
    return 0;
}