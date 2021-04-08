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

bool check(vector<int> &a)
{
	int x = a[0];
	for (int i = 1; i < a.size(); i++)
		if (a[i] != x) return false;
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a;
	vector<P> dict;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
		dict.push_back(P(num, i));
	}
	sort(dict.begin(), dict.end());
	for (int i = 0; i < n; i++)
	{
		if (check(a))
		{
			cout << i << endl;
			return;
		}
		int k = dict[i].second;
		int nk;
		if (k == a.size() - 1)	// end
			nk = k - 1;
		else if (k == 0)
			nk = k + 1;
		else
			nk = a[k + 1] > a[k - 1]? k - 1: k + 1;

		a[nk] += a[k];
		auto ite = a.begin() + k;
		a.erase(ite);

		for (int j = i + 1; j < n; j++)
		{
			if (dict[j].second > k)
				dict[j].second -= 1;
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
