#include <iostream>
#include <queue>
using namespace std;

int n, k;
int seq[200000];
int sum[200000];

deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
            seq[i + n] = seq[i];
        }
        sum[0] = 0;
        for (int i = 1; i < n + k; i++) sum[i] = sum[i - 1] + seq[i - 1];
        int l, r;
        int ans = -100000000;
        for (int i = 1; i < n + k; i++)
        {
            while (!dq.empty() && sum[i - 1] < sum[dq.back()])
                dq.pop_back();
            while (!dq.empty() && dq.front() <= i - k - 1)
                dq.pop_front();
            dq.push_back(i - 1);
            if (sum[i] - sum[dq.front()] > ans)
            {
                ans = sum[i] - sum[dq.front()];
                l = dq.front() + 1;
                r = (i - 1) % n + 1;
            }
        }
        cout << ans << ' ' << l << ' ' << r << endl;

        dq.clear();
    }
    return 0;
}