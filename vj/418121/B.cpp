#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> ans;

void dfs(int width, int bit, ll sum, ll res)
{
    if (sum > 10 || bit >= width) return;
    if (bit == width - 1)
    {
        if (sum == 0) return;
        res = res * 10 + 10 - sum;
        ans.push_back(res);
        return;
    }
    for (ll i = (bit == 0? 1: 0); i <= 9; i++)
    {
        dfs(width, bit + 1, sum + i, res * 10 + i);
    }
}

int main()
{
    for (int i = 0; ans.size() <= 10000; i++)
    {
        dfs(i, 0, 0, 0);
    }
    sort(ans.begin(), ans.end());
    int k;
    cin >> k;
    cout << ans[k - 1] << endl;
    return 0;
}