#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define INF 2e9

typedef long long ll;

set<int> s;
int res = 0;
void solve()
{
	int op, x;
	cin >> op >> x;
	if (op == 1)
	{
		s.insert(x);
	}
	else
	{
		set<int>::iterator ite;
		for (ite = s.begin(); ite != s.end(); ite++)
		{
			if (*ite % x == 0)
			{
				res += s.count(*ite);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	cout << res << endl;
	return 0;
}
