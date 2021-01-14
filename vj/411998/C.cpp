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
int N, K;
int vis[300000];

void solve()
{
	memset(vis, -1, sizeof(vis));
	vis[N] = 0;
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int pos = q.front(); q.pop();
		int npos = pos - 1;
		if (npos >= 0 && vis[npos] == -1)
		{
			vis[npos] = vis[pos] + 1;
			q.push(npos);
		}
		if (npos == K)
		{
			cout << vis[npos] << endl;
			return;
		}
		npos = pos + 1;
		if (npos >= 0 && vis[npos] == -1)
		{
			vis[npos] = vis[pos] + 1;
			q.push(npos);
		}
		if (npos == K)
		{
			cout << vis[npos] << endl;
			return;
		}
		npos = pos * 2;
		if (npos >= 0 && npos <= 200000 && vis[npos] == -1)
		{
			vis[npos] = vis[pos] + 1;
			q.push(npos);
		}
		if (npos == K)
		{
			cout << vis[npos] << endl;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K;
	solve();
	/*
	for (int i = 0; i < 21; i++)
		cout << vis[i] << ' ';
	cout << endl;
	*/
	return 0;
}
