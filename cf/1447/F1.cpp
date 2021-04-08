#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
/*
struct node
{
	int t = 0, a;
	bool operator <(const node s) { return t < s.t; }
} map[101];	// map[i] = num of i
*/
int map[101];

void solve()
{
	cin >> n;

	//fill(map, map + n, 0);

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		//map[b].a = b;
		//map[b].t++;
		map[b]++;
	}

	sort(map + 1, map + n + 1);
	//int delta = map[n].t - map[n - 1].t;
	int delta = map[n] - map[n - 1];
	cout << n - delta << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
