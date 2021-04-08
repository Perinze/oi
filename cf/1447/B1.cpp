#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define INF 2e9

typedef long long ll;
int n, m;
int a[10][10];

void solve()
{
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			q.push(a[i][j]);
		}


}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
