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

void solve()
{
	int n;
	cin >> n;
	vector<int> xn;
	set<int> area;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		xn.push_back(x);
	}
	//cout << "read complete" << endl;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int val = xn[j] - xn[i];
			area.insert(val);
		}
	cout << area.size() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
