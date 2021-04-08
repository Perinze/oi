#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> P;

const int MAXL = 15;

int N;
vector<int> result;	// max 18
set<int> used;
stack<P> s;	// stack

bool flag = false;	// first dfs entry
void dfs()
{
	//cout << "enter dfs()" << endl;
	if (!flag)	// l == 0 stand for init
	{
		s.push(P(0, 0));
		flag = true;
	}

	while (s.size())
	{
		P p = s.top(); s.pop();
		//cout << "take (" << p.first << ", " << p.second << ") from stack" << endl;
		while (p.second && p.second <= result.size())
		{
			//cout << "backward" << endl;
			used.erase(*(result.end() - 1));
			result.pop_back();
		}
		if (p.second)
		{
			result.push_back(p.first);
			//cout << "result add " << p.first << endl;
			used.insert(p.first);
			//cout << "used add " << p.first << endl;
		}
		if (p.second == MAXL || p.second == N)
		{
			return;
			//cout << "exit dfs()" << endl;
		}

		for (int i = N; i > N - MAXL && i > 0; i--)
		{
			set<int>::iterator ite = used.find(i);
			if (ite == used.end())
			{
				s.push(P(i, p.second + 1));
				//cout << "push (" << i << ", " << p.second + 1 << ") into stack" << endl;
			}
		}
	}
	//cout << "stack empty!" << endl;
}

void print_res(int l, int r)
{
	int delta = N - MAXL;
	if (N <= MAXL) delta = 0;

	if (l > N - MAXL)
	{
		//cout << "first" << endl;
		int res = 0;
		for (int i = l - delta; i < r - delta; i++)
		{
			//cout << "res += result[" << i << "]: " << result[i] << endl;
			res += result[i];
		}
		cout << res << endl;
		return;
	}
	if (r <= N - MAXL)
	{
		//cout << "second" << endl;
		cout << r * (r + 1) / 2 - (l - 1) * l / 2 << endl;
		return;
	}
	//cout << "third" << endl;
	int res = 0;
	for (int i = N - MAXL - delta; i < r - delta; i++)
		res += result[i];
	//cout << "res = " << res << endl;
	cout << (N - MAXL) * (N - MAXL + 1) / 2 - (l - 1) * l / 2 + res << endl;
}

int main()
{
	int Q;
	cin >> N >> Q;
	dfs();
	//for (int i = 0; i < N && i < MAXL; i++) cout << result[i] << ' ';
	//cout << endl;
	for (; Q; Q--)
	{
		int q; cin >> q;
		if (q == 1)
		{
			int l, r; cin >> l >> r;
			l--;
			print_res(l, r);
		}
		else
		{
			int t;
			cin >> t;
			for (; t; t--)
				dfs();
			//for (int i = N - MAXL + 1; i < N; i++) cout << result[i] << ' ';
			//for (int i = 0; i < N && i < MAXL; i++) cout << result[i] << ' ';
			//cout << endl;
		}
	}
	return 0;
}
