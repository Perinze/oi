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
ll N;

void solve()
{
	queue<ll> q;
	q.push(1);
	while (!q.empty())
	{
		ll num = q.front(); q.pop();
		if (num % N == 0)
		{
			cout << num << endl;
			return;
		}
		q.push(num * 10);
		q.push(num * 10 + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> N && N != 0)
		solve();
	return 0;
}
