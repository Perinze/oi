#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

void solve()
{
	char c;
	bool nega = false;
	vector<char> num;
	while ((c = cin.get()) != EOF && (c == '-' || (c >= '0' && c <= '9')))
	{
		if (c == '-')
		{
			nega = true;
			continue;
		}
		num.push_back(c);
	}
	reverse(num.begin(), num.end());
	if (num.size() != 1)
		while (num[0] == '0')
			num.erase(num.begin());
	if (nega) cout << '-';
	for (int i = 0; i < num.size(); i++)
		cout << num[i];
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
