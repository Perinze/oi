#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int stacka = 0, stackb = 0;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(') stacka++;
		else if (c == '[') stackb++;
		else if (c == ')')
		{
			if (stacka > 0)
			{
				stacka--;
				res++;
			}
		}
		else if (c == ']')
		{
			if (stackb > 0)
			{
				stackb--;
				res++;
			}
		}
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
