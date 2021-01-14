#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

int count(int diff)
{
	int res = 0;
	for (; diff > 0; diff >>= 1)
	{
		if (diff & 1)
		{
			res++;
		}
	}
	return res;
}

int time(int n)
{
	int res = 0;
	for (int x = 0; x < n; x++)
	{
		int diff = x ^ (x + 1);
		res += count(diff);
	}
	return res;
}

void solve()
{
	for (int i = 0; i < 100; i++)
	{
		cout << time(i) << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
