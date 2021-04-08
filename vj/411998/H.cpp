#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;
int A, B, C;
set<P> s;
vector<int> solution;
vector<int> opt;
/*
 * 0	FILL(1)
 * 1	FILL(2)
 * 2	DROP(1)
 * 3	DROP(2)
 * 4	POUR(1, 2)
 * 5	POUR(2, 1)
 */

P pour(bool d, P p)
{
	if (d)	// A -> B
	{
		if (B - p.second <= p.first)
		{
			return P(p.first - B + p.second, B);
		}
		else
		{
			return P(0, p.second + p.first);
		}
	}
	else	// B -> A
	{
		if (A - p.first <= p.second)
		{
			return P(A, p.second - A + p.first);
		}
		else
		{
			return P(p.first + p.second, 0);
		}
	}
}

void print_solution()
{
	cout << opt.size() << endl;
	for (int i = 0; i < opt.size(); i++)
	{
		switch (opt[i])
		{
			case 0:
				cout << "FILL(1)" << endl;
				break;
			case 1:
				cout << "FILL(2)" << endl;
				break;
			case 2:
				cout << "DROP(1)" << endl;
				break;
			case 3:
				cout << "DROP(2)" << endl;
				break;
			case 4:
				cout << "POUR(1,2)" << endl;
				break;
			case 5:
				cout << "POUR(2,1)" << endl;
				break;
		}
	}
}

void dfs(P p)
{
	if ((p.first == C || p.second == C) && (opt.empty() || solution.size() < opt.size()))
	{
		opt = solution;
	}

	if (s.count(p)) return;
	s.insert(p);

	solution.push_back(0);
	dfs(P(A, p.second));
	solution.pop_back();

	solution.push_back(1);
	dfs(P(p.first, B));
	solution.pop_back();

	solution.push_back(2);
	dfs(P(0, p.second));
	solution.pop_back();

	solution.push_back(3);
	dfs(P(p.first, 0));
	solution.pop_back();

	solution.push_back(4);
	dfs(pour(1, p));
	solution.pop_back();

	solution.push_back(5);
	dfs(pour(0, p));
	solution.pop_back();

	s.erase(p);
}

void solve()
{
	cin >> A >> B >> C;
	dfs(P(0, 0));
	if (opt.empty())
		cout << -1;
	else
		print_solution();
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
