#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;
int n;

void shuffle(string &str)
{
	string temp = str;
	for (int i = 0; i < str.size() / 2; i++)
	{
		int j = i * 2 + 1;
		temp[j] = str[i];
	}
	for (int i = str.size() / 2; i < str.size(); i++)
	{
		int j = (i - str.size() / 2) * 2;
		temp[j] = str[i];
	}
	str = temp;
	//cout << str << endl;
}

void solve(int t)
{
	cin >> n;
	string s1, s2, tar;
	cin >> s1 >> s2 >> tar;
	cout << t << ' ';
	string s = s1 + s2;
	set<string> used;
	for (int i = 0; !used.count(s); i++)
	{
		//cout << "shuffled " << i << " times: " << s << endl;
		if (s == tar)
		{
			cout << i << endl;
			return;
		}
		used.insert(s);
		shuffle(s);
	}
	cout << -1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
