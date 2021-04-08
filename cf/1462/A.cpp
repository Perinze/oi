#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	list<int> li;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		li.push_back(a);
	}
	bool left_ = true;
	list<int>::iterator ite;
	while (!li.empty())
	{
		if (left_) ite = li.begin();
		else
		{
			ite = li.end();
			ite--;
		}
		cout << *ite << ' ';
		li.erase(ite);
		left_ = !left_;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
