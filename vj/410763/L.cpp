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

void solve()
{
	do
	{
		cout << str << endl;
	} while (next_permutation(str.begin(), str.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> str;
	solve();
	return 0;
}
