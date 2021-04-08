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
int N;
vector<P> map;
int deg[100010];

void solve()
{
	memset(deg, 0, sizeof(deg));
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		int w;
		cin >> w;
		map.push_back(P(w, i));
		sum += w;
	}
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[u]++;
		deg[v]++;
	}
	cout << sum << ' ';
	sort(map.rbegin(), map.rend());
	for (int i = 0; i < N; i++)
	{
		int v = map[i].second;
		int w = map[i].first;
		while (deg[v] > 1)
		{
			deg[v]--;
			sum += w;
			cout << sum << ' ';
		}
	}
	cout << endl;

	map.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
