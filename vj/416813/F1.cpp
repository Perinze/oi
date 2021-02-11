#include <cstdio>
#include <cstring>
#include <stack>

int main()
{
    int T;
    scanf("%d", &T);

    int a[50000], l[50000], r[50000];
    for (int t = 1; t <= T; t++)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", a + i);

        std::stack<int> s;
        for (int i = 0; i < N; i++)
        {
            if (s.empty() || a[s.top()] > a[i])
            {
                l[i] = -1;
                s.push(i);
            }
            else
            {
                while (!s.empty() && a[i] > a[s.top()])
                {
                    l[i] = s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        while (!s.empty()) s.pop();
        for (int i = N - 1; i >= 0; i--)
        {
            if (s.empty() || a[s.top()] > a[i])
            {
                r[i] = -1;
                s.push(i);
            }
            else
            {
                while (!s.empty() && a[i] > a[s.top()])
                {
                    r[i] = s.top();
                    s.pop();
                }
                s.push(i);
            }
            
        }

        printf("Case %d:\n", t);
        for (int i = 0; i < N; i++) printf("%d %d\n", l[i] + 1, r[i] + 1);
    }
    return 0;
}