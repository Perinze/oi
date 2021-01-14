#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <sstream>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	string str;
	while (cin >> str)
	{
		stringstream ss;
		ss << str;
		bool isnum = true;
		string substr;
		list<double> xp;
		while (ss >> substr)
		{
			cout << substr << endl;
			stringstream item(substr);
			if (isnum)
			{
				double num;
				item >> num;
				xp.push_back(num);
			}
			else
			{
				cout << '\'' << substr << '\'' << endl;
				if (substr == "+") xp.push_back(-1);
				else if (substr == "-") xp.push_back(-2);
				else if (substr == "*") xp.push_back(-3);
				else if (substr == "/") xp.push_back(-4);
			}

			isnum = !isnum;
		}

		for (auto ite = xp.begin(); ite != xp.end(); ite++)
			cout << *ite << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
