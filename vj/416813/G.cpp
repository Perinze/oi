#include <cstdio>
#include <stack>

int main()
{
    int N, cas = 1;
    while (scanf("%d", &N) != EOF)
    {
        std::stack<int> s;
        s.push(0);
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int h;
            scanf("%d", &h);

            while (!s.empty() && s.top() > h)
            {
                s.pop();
            }
            if (s.empty() || h > s.top())
            {
                ans++;
                s.push(h);
            }
        }

        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}