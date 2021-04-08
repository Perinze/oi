#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, double> ITEM;

void print1(stack<int> s, vector<ITEM> exp)
{
    #ifdef DEBUG
    cout << "STACK: ";
    while (!s.empty())
    {
        switch (s.top())
        {
            case 1: cout << "+ "; break;
            case 2: cout << "- "; break;
            case 3: cout << "* "; break;
            case 4: cout << "/ "; break;
        }
        s.pop();
    }
    cout << endl;

    cout << "EXP: ";
    for (int i = 0; i < exp.size(); i++)
    {
        switch (exp[i].first)
        {
            case 0: cout << exp[i].second << ' '; break;
            case 1: cout << "+ "; break;
            case 2: cout << "- "; break;
            case 3: cout << "* "; break;
            case 4: cout << "/ "; break;
        }
    }
    cout << endl;
    #endif
}

void print2(stack<double> ds)
{
    #ifdef DEBUG
    cout << "DOUBLE STACK: ";
    while (!ds.empty())
    {
        cout << ds.top() << ' ';
        ds.pop();
    }
    cout << endl;
    #endif
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
        vector<ITEM> exp;
        string item;
        stack<int> s;
        while (ss >> item)
        {
            if (item == "+") 
            {
                while (!s.empty() && s.top() >= 3)    // MUL or DIV
                {
                    exp.push_back(ITEM(s.top(), 0));
                    s.pop();
                }
                s.push(1);
            }
            else if (item == "-") 
            {
                while (!s.empty() && s.top() >= 3)    // MUL or DIV
                {
                    exp.push_back(ITEM(s.top(), 0));
                    s.pop();
                }
                s.push(2);
            }
            else if (item == "*") 
            {
                while (!s.empty() && s.top() >= 4)    // DIV
                {
                    exp.push_back(ITEM(s.top(), 0));
                    s.pop();
                }
                s.push(3);
            }
            else if (item == "/") 
            {
                s.push(4);
            }
            else 
            {
                exp.push_back(ITEM(0, stod(item)));
            }
            print1(s, exp);
        }
        while (!s.empty())
        {
            exp.push_back(ITEM(s.top(), 0));
            s.pop();
        }
        print1(s, exp);

        stack<double> ds;
        for (int i = 0; i < exp.size(); i++)
        {
            int type = exp[i].first;
            if (type == 0)  // number
            {
                ds.push(exp[i].second);
            }
            else if (type == 1)
            {
                double b = ds.top(); ds.pop();
                double a = ds.top(); ds.pop();
                ds.push(a + b);
            }
            else if (type == 2)
            {
                double b = ds.top(); ds.pop();
                double a = ds.top(); ds.pop();
                ds.push(a - b);
            }
            else if (type == 3)
            {
                double b = ds.top(); ds.pop();
                double a = ds.top(); ds.pop();
                ds.push(a * b);
            }
            else if (type == 4)
            {
                double b = ds.top(); ds.pop();
                double a = ds.top(); ds.pop();
                ds.push(a / b);
            }
            print2(ds);
        }

        cout << ds.top() << endl;
    }
    return 0;
}