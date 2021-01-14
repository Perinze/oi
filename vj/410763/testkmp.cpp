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

const int MAX_P = 2000;

string pattern;
int next_[MAX_P];

void init()
{
	next_[0] = 0;
	next_[1] = 1;
	for (int i = 2; i < pattern.size(); i++)
	{
		cout << endl;
		string pre_str = pattern.substr(0, i);
		cout << "pre_str = \"" << pre_str << "\"\n";
		int ms = 0;
		for (int s = 1; s < pre_str.size(); s++)
		{
			cout << "size = " << s << endl;

			string left_str = pre_str.substr(0, s);
			cout << "left_str = \"" << left_str << "\"\n";

			string right_str = pre_str.substr(pre_str.size() - s, s);
			cout << "right_str = \"" << right_str << "\"\n";

			if (left_str == right_str) ms = max(ms, s);
		}
		next_[i] = ms + 1;
	}
}

void solve()
{
	cin >> pattern;
	init();
	for (int i = 0; i < pattern.size(); i++)
		cout << next_[i] << ' ';
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
