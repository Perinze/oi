#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    for (;;)
    {
        stack<double> ds;
        char op;
        double num;
        scanf("%lf%c", &num, &op);
        if (num == 0 && op == '\n') break;
        ds.push(num);

        while (scanf("%c%lf", &op, &num) != EOF)
        {
            if (op == '+')
                ds.push(num);
            else if (op == '-')
                ds.push(-num);
            else if (op == '*')
            {
                double tmp = ds.top();
                ds.pop();
                ds.push(tmp * num);
            }
            else
            {
                double tmp = ds.top();
                ds.pop();
                ds.push(tmp / num);
            }
            if ((op = getchar()) == '\n') break;
        }
        double ans = 0.0;
        while (!ds.empty())
        {
            ans += ds.top();
            ds.pop();
        }

        printf("%.2lf\n", ans);
    }
    return 0;
}