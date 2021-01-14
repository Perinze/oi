#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

void solve()
{
	string str;
	while (cin >> str)
	{
		int len = str.length();
		for (int i = 0; i < len; i++)
			if (str[i] == '5') str[i] = ' ';

		int num;
		vector<int> a;
		stringstream ss;
		ss << str;
		while (ss >> num) a.push_back(num);

		sort(a.begin(), a.end());
		len = a.size();
		for (int i = 0; i < len; i++) cout << a[i] << (i == len - 1? '\n': ' ');
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
