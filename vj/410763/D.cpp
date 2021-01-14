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

void solve()
{
	int a, b, x;
	cin >> a >> b >> x;

	int ch;
	if (a < b) ch = 1;	// 1 start first
	else ch = 0;	// 0 start first

	// init x
	list<int> ans;
	list<int>::iterator ite;
	while (x--)
	{
		if (ch == 0) a--;
		else b--;
		ans.push_back(ch);
		ch = !ch;
	}
	if (ch == 0) a--;
	else b--;
	ans.push_back(ch);

	// output 1
	for (ite = ans.begin(); ite != ans.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;

	// insert 1
	ite = ans.begin();
	if (a < b) ite++;
	while (b--)
	{
		ans.insert(ite, 1);
	}

	// output 2
	for (ite = ans.begin(); ite != ans.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;

	// insert 0
	ite = ans.begin();
	if (a >= b) ite++;
	while (a--)
	{
		ans.insert(ite, 0);
	}

	// output 3
	for (ite = ans.begin(); ite != ans.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;


	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
