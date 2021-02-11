#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void print(vector<string> exp)
{
    for (int i = 0; i < exp.size(); i++) cout << exp[i] << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    string line;
    for (;;)
    {
        getline(cin, line);
        if (line == "0") break;
        stringstream ss(line);
        vector<string> exp;
        string item;
        while (ss >> item) exp.push_back(item);

        stack<

        print(exp);
    }
    return 0;
}