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
		//if (b == s.b) return a > s.a;
		//return b < s.b;
		return a < s.a;
	}
} p[200000];

ll calc(int n)
{
	ll delivery;
	if (n) delivery = p[n-1].a;
	else delivery = 0;
	ll self = 0;
	for (int i = n; i < N; i++)
	{
		self += p[i].b;
	}
	return max(delivery, self);
}

ll search()
{
	ll res = INF, lres = INF;
	for (int i = 0; i <= N; i++)
	{
		res = min(res, calc(i));
		if (res > lres) break;
		lres = res;
	}
	return res;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].a;
	for (int i = 0; i < N; i++) cin >> p[i].b;

	sort(p, p + N);
	//for (int i = 0; i <= N; i++) cout << calc(i) << ' ';
	//cout << endl;

	cout << search()  << endl;
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
