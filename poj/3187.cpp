#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
int N, sum;

int lolist[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
bool exists[11];
int lists[11][10];
string ans;

void search(int x, int l)	// x is the first num, l to level, start with 1
{
	int* crt = lists[l];
	int* lst = lists[l - 1];

	set<int> s;
	crt[0] = x;
	s.insert(x);
	int lo = lolist[N - l];
	for (int i = 1; i < l; i++)
	{
		crt[i] = lst[i - 1] - crt[i - 1];
		if (crt[i] < lo) return;
		if (s.count(crt[i]) > 0) return;
		s.insert(crt[i]);
	}

	if (l == N)
	{
#ifdef DEBUG_
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
				cout << lists[i][j] << ' ';
			cout << endl;
		}
#endif
		// check
		memset(exists, 0, sizeof(exists));
		for (int i = 0; i < N; i++)
		{
			exists[crt[i]] = true;
		}
		for (int i = 1; i <= N; i++)
		{
			if (!exists[i]) return;
		}

		// compare answer
		string temp;
		for (int i = 0; i < N; i++)
		{
			temp.push_back(crt[i] + '0');
		}
		//cout << temp << endl;
		ans = min(ans, temp);
		return;
	}

	for (int i = 1; i < crt[0]; i++)
	{
		search(i, l + 1);
	}
}

void solve()
{
	cin >> N >> sum;
	ans = "999999999999";
	lists[1][0] = sum;
	for (int i = 1; i <= sum / 2; i++)
		search(i, 2);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
