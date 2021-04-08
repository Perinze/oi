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
string str;
bool used['z' + 1];

bool ispalin(int l, int r)
{
	for (int i = 0; i <= (r - l) / 2; i++)
	{
		if (str[l + i] != str[r - i]) return false;
	}
	return true;
}

void solve()
{
	cin >> str;
	memset(used, 0, sizeof(used));
	for (int i = 0; i < str.size(); i++)
	{
		used[str[i]] = true;
	}
	char n = 'a';
	int ans = 0;
	for (int size = str.size(); size > 0; size--)
	{
		for (int s = 0; s + size <= str.size(); s++)
		{
			if (ispalin(s, s + size - 1))
			{
				int m = (s * 2 + size - 1) / 2 + 1;
				while (
				ans++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
