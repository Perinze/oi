#include <iostream>
using namespace std;

typedef long long ll;
ll dp[31][31];

void init()
{
    for (int i = 1; i <= 30; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i * i;
    }
    for (int i = 2; i <= 30; i++)
        for (int j = 2; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] * i * i / j;
}

int main()
{
    init();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;
        cout << "Case " << t << ": ";
        cout << dp[n][k] << endl;
    }
    return 0;
}