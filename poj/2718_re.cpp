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
	int T;
	string temp;
	cin >> T;
	getline(cin, temp);
	while (T--)
	{
		getline(cin, temp);
		vector<int> digit;
		for (int i = 0; i < temp.size(); i += 2)
		{
			digit.push_back(temp[i] - '0');
		}

		int mid = digit.size() / 2;
		int num1, num2;
		int ans = INF;

		do
		{
			num1 = 0, num2 = 0;
			if (!digit[0] || !digit[mid] && digit.size() > 2)
				continue;
			for (int i = 0; i < mid; i++)
			{
				num1 = num1 * 10 + digit[i];
			}
			for (int i = mid; i < digit.size(); i++)
			{
				num2 = num2 * 10 + digit[i];
			}
			ans = min(ans, abs(num1 - num2));
		}
		while (next_permutation(digit.begin(), digit.end()));
		cout << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
