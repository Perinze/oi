#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<double, double> P;

const int MAX_N = 50010;
int N, dat[2 * MAX_N];

void init(int N_)
{
	N = 1;
	while (N < N_) N *= 2;
	for (int i = 0; i < 2 * N - 1; i++) dat[i] = P(0.0, 0.0);
}

void update(int k, P p)
{
	k += N - 1;
	dat[k] = p;
	while (k > 0)
	{
		k = (k - 1) / 2;
		dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
	}
}

void solve()
{
	int N_, T;
	cin >> N_ >> T;
	double x = 0.0, y = 0.0;
	for (int i = 0; i < N_; i++)
	{
		int op; double dx, dy;
		cin >> op >> dx >> dy;

		if (op == 1)
		{
			shift(x, y, dx, dy);
		}
		else
		{
			rotate(x, y, ang);
		}
		
		update(i, P(x, y));
	}

	for (int i = 0; i < T; i++)
	{
		int left, right;
		cin >> left >> right;	//[left,right]
		left--;//[left,right)
		P p = query(left, right, 0, 0, N);
		cout << p.first << ' ' << p.second << endl;
	}
}

int main()
{
	cout << fixed << setprecision(3);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

