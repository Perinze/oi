#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	string line;
	while (cin >> line)
	{
		stringstream ss;
		ss << line;
		string op;
		list<string> exp;
		while (ss >> op)
		{
			exp.push_back(op);
		}
		list<string>::iterator ite;
		for (ite = exp.begin(); ite != exp.end(); ite++)
		{
			if (*ite == "+")
			{
				ite++;
				double r = stod(*ite);
				ite--; ite--;
				double l = stod(*ite), 
				*ite = to_string(l + r);
				ite++;
				exp.erase(ite);
				exp.erase(ite);
			}
		}
		for (ite = exp.begin(); ite != exp.end(); ite++)
			cout << *ite << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
