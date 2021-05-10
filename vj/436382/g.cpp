#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 55;
int n;
ll a[maxn];
ll dp[maxn][maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 2; i++)
        dp[i][i] = a[0] * a[i] * a[i + 1];
}