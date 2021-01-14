
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;


void solve()
{
	int n, z;
	cin >> n >> z;
	vector<P> li;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < li.size(); j++)
		{
			if ((li[j].first + a) % z == 0)
			{
				li[j].second = min(li[j].second, 
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
