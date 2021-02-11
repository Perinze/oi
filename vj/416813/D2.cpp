#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

void print(stack<double> ds, stack<int> op)
{
    #ifdef DEBUG
    cout << "DOUBLE STACK: ";
    while (!ds.empty())
    {
        cout << ds.top() << ' ';
        ds.pop();
    }
    cout << endl;
    cout << "OPERATION STACK: ";
    while (!op.empty())
    {
        switch (op.top())
        {
            case 1: cout << "+ "; break;
            case 2: cout << "- "; break;
            case 3: cout << "* "; break;
            case 4: cout << "/ "; break;
        }
        op.pop();
    }
    cout << endl << endl;
    #endif
}

double calc(double a, double b, int op)
{
    switch (op)
    {
        case 1: return a + b;
        case 2: return a - b;
        case 3: return a * b;
        case 4: return a / b;
    };
    return 0.0;
}

int main()
{
    cout << fixed << setprecision(2);
    string line;
    for (;;)
    {
        getline(cin, line);
        if (line == "0") break;
        stringstream ss(line);
        string item;

        stack<double> ds;
        stack<int> op;
        while (ss >> item)
        {
            if (item == "+" || item == "-") 
            {
                if (!op.empty())
                {
                    int crt_op = op.top(); op.pop();
                    double b = ds.top(); ds.pop();
                    double a = ds.top(); ds.pop();
                    ds.push(calc(a, b, crt_op));
                }
                if (item == "+") op.push(1);
                else op.push(2);
                print(ds, op);
            }
            else if (item == "*" || item == "/") 
            {
                string r;
                ss >> r;
                double b = stod(r);
                double a = ds.top(); ds.pop();
                if (item == "*") ds.push(a * b);
                else ds.push(a / b);
                print(ds, op);
            }
            else 
            {
                ds.push(stod(item));
                print(ds, op);
            }
        }
        while (!op.empty())
        {
            double b = ds.top(); ds.pop();
            double a = ds.top(); ds.pop();
            int crt_op = op.top(); op.pop();
            ds.push(calc(a, b, crt_op));
            print(ds, op);
        }

        cout << ds.top() << endl;
    }
    return 0;
}