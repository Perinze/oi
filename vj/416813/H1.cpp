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
typedef pair<int, int> P;

bool solve()
{
	string line;
	getline(cin, line);
	if (line.empty()) return false;

	vector<int> a;
	int num = 0;
	char c, l = '5';
	for (int p = 0; p < line.size(); p++)
	{
		c = line[p];
		if (c != '5') num = num * 10 + c - '0';
		if (l != '5' && c == '5')
			a.push_back(num);
		if (c == '5') num = 0;
		l = c;
	}
	if (c != '5') a.push_back(num);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << (i == a.size() - 1? '\n': ' ');

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	while (solve());
	cout << endl;
	return 0;
}
