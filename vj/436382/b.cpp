#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 60;
int n, k;
ll w[maxn];
ll A, B;
ll C[maxn][maxn];

void init()
{
    C[0][0] = 1;
    for (int i = 1; i <= 50; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
}

ll cnt(ll x)
{
    ll ans = 0, num = k;
    for (int i = 1; i <= n; i++) {
        if (x < w[i]) continue;
        ans += C[n - i][num];
        if (num == 0) return ans;
        x -= w[i];
        num--;
    }
    return ans + (num == 0);
}

int main()
{
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cin >> A >> B;
    sort(w + 1, w + 1 + n);
    reverse(w + 1, w + 1 + n);
    cout << cnt(B) - cnt(A - 1) << endl;
    return 0;
}