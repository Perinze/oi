#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define INF 2e9

typedef long long ll;
int n; ll W;
struct node
{
	int id; ll w;
	bool operator <(const node s) { return w < s.w; }
} item[200001];

void no_solution();
void solution(int s, int t);

void solve()
{
	cin >> n >> W;
	ll hfW = (W + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		item[i].id = i;
		cin >> item[i].w;
	}

	sort(item + 1, item + n + 1);

	int s = 1, t = 1; ll sum = 0;
	for (;;)
	{
		while (t <= n && sum < hfW)
		{
			sum += item[t++].w;
		}

		if (sum < hfW)
		{
			no_solution();
			break;
		}
		if (sum <= W)
		{
			solution(s, t);
			break;
		}
		sum -= item[s++].w;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}

void no_solution()
{
	cout << -1 << endl;
}

void solution(int s, int t)
{
	cout << t - s << endl;
	for (int i = s; i < t; i++)
	{
		cout << item[i].id << ' ';
	}
	cout << endl;
}
