#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

void solve()
{
	int a, b, x;
	cin >> a >> b >> x;

	int ch;
	if (a > b) ch = 0;
	else ch = 1;

	vector<int> ans;
	vector<int>::iterator ite;
	for (int i = 0; i <= x; i++)
	{
		if (ch == 0) a--;
		else b--;
		ans.push_back(ch);
		ch = !ch;
	}

	/*
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	*/

	for (int i = 0; i < a; i++)
	{
		ite = find(ans.begin(), ans.end(), 0);
		if (ite == ans.end()) cout << "wtf" << endl;
		ans.insert(ite, 0);
	}

	/*
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	*/

	for (int i = 0; i < b; i++)
	{
		ite = find(ans.begin(), ans.end(), 1);
		if (ite == ans.end()) cout << "wtf" << endl;
		ans.insert(ite, 1);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
