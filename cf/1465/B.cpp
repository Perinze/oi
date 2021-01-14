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

void solve()
{
	ll num;
	cin >> num;
	string str = to_string(num);
	
	bool OK = false;
	while (!OK)
	{
		OK = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '0')
				continue;
			if (num % (str[i] - '0'))
			{
				OK = false;
				num++;
				str = to_string(num);
				break;
			}
		}
	}
	cout << num << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
