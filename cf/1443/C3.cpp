#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 2e15;
int N;
struct node
{
	ll a, b;	// a for delivery, b for self taking
	bool operator <(const node s)
	{
		if (a == s.a) return b < s.b;
		return a > s.a;
	}
} p[200000];

ll search()
{
	ll selftake = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		if (selftake + p[i].b <= p[i].a)
			selftake += p[i].b;
		else break;
	}
	if (i >= N) return selftake;
	return max(selftake, p[i].a);
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].a;
	for (int i = 0; i < N; i++) cin >> p[i].b;

	sort(p, p + N);
	//for (int i = 0; i <= N; i++) cout << calc(i) << ' ';
	//cout << endl;

	cout << search() << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		solve();
	}
	return 0;
}
