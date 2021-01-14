#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
//#include <vector>
using namespace std;

typedef pair<int, int> P;

int N;
set<int> used;
stack<P> s;	// stack
//vector<int> result;
int bit[200001], ed = 0;

int sum(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x)
{
	while (i <= N)
	{
		bit[i] += x;
		i += i & -i;
	}
}

inline int get(int i)
{
	return sum(i) - sum(i - 1);
}

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
		while (p.second && p.second <= ed)
		{
			//cout << "backward" << endl;
			used.erase(get(ed));
			//result.pop_back();
			add(ed, -get(ed)); ed--;
		}
		if (p.second)
		{
			//result.push_back(p.first);
			add(++ed, p.first);
			//cout << "result add " << p.first << endl;
			used.insert(p.first);
			//cout << "used add " << p.first << endl;
		}
		if (p.second == N)
		{
			return;
			//cout << "exit dfs()" << endl;
		}

		for (int i = N; i >= 1; i--)
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
	//for (int i = 0; i < N; i++) cout << result[i] << ' ';
	cout << sum(r) - sum(l) << endl;
}

int main()
{
	int Q;
	cin >> N >> Q;
	dfs();
	//for (int i = 1; i <= N; i++) cout << get(i) << ' ';
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
			//for (int i = 1; i <= N; i++) cout << get(i) << ' ';
			//cout << endl;
		}
	}
	return 0;
}
