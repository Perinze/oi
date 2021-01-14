// #include <stack>
// #include <set>
// #include <vector>

typedef pair<int, int> P;

int N;
vector<int> result;
set<int> used;
stack<P> s;	// stack

void dfs(int n, int l)	// expect dfs(0, 0)
{
	if (l == 0)	// l == 0 stand for init
		s.push(P(n, l));

	while (s.size())
	{
		P p = s.top(); s.pop();
		while (p.second <= result.size())
		{
			used.erase(*(result.end() - 1));
			result.pop_back();
		}
		result.push_back(p.first);
		used.insert(p.first);
		if (p.second == N)
		{
			return;
		}

		for (int i = N; i >= 1; i--)
		{
			set<int>::iterator ite = used.find(i);
			if (ite == used.end())
			{
				s.push(P(i, p.second + 1));
			}
		}
	}
}

void print_res()
{
	for (int i = 1; i <= N; i++) cout << result[i] << ' ';
	cout << endl;
}
