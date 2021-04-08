#include <cstdio>
#include <cstring>
#include <stack>

const int MAXN = 1000001;
const int INF = 10000;

int sum[MAXN], ans[MAXN];

void solve()
{
    int Q;
    while (scanf("%d\n", &Q) != EOF)
    {
        char cmd;
        int p, x;
        std::stack<int> left, right;
        memset(sum, 0, sizeof(sum));
        memset(ans, 0, sizeof(ans));
        ans[0] = -INF;
        for (int q = 0; q < Q; q++)
        {
            if ((cmd = getchar()) == 'I')
            {
                scanf("%d", &x);
                left.push(x);
                p = (int)left.size();
                sum[p] = sum[p - 1] + x;
                ans[p] = std::max(ans[p - 1], sum[p]);
            }
            else if (cmd == 'L')
            {
                if (!left.empty())
                {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if (cmd == 'R')
            {
                if (!right.empty())
                {
                    left.push(right.top());
                    right.pop();
                    p = (int)left.size();
                    sum[p] = sum[p - 1] + left.top();
                    ans[p] = std::max(ans[p - 1], sum[p]);
                }
            }
            else if (cmd == 'D')
            {
                if (!left.empty())
                {
                    left.pop();
                }
            }
            else
            {
                scanf("%d", &x);
                printf("%d\n", ans[x]);
            }
            getchar();
        }
    }
}

int main()
{
    solve();
    return 0;
}