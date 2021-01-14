#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define INF 2e9

typedef long long ll;

struct node
{
	int a, b;
	bool operator <(const node s)
	{
		if (a == s.a)
		{
			return b < s.b;
		}
		return a > s.a;
	}
} Rest[200020];

int N;

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Rest[i].a;
	for (int i = 0; i < N; i++) cin >> Rest[i].b;
	Rest[N].a = 0;

	sort(Rest, Rest + N);
	//for (int i = 0; i < N; i++) cout <<  Rest[i].a << ' ';
	//cout << endl;
	//for (int i = 0; i < N; i++) cout <<  Rest[i].b << ' ';
	//cout << endl;

	int delivery = Rest[0].a;
	int self = 0;
	for (int i = 0; i <= N; i++)
	{
		//cout << delivery << ", " << self << endl;
		if (delivery <= self)
		{
			//cout << "delivery <= self" << endl;
			cout << min(Rest[i - 1].a, self) << endl;
			break;
		}
		delivery = Rest[i + 1].a;
		self += Rest[i].b;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
