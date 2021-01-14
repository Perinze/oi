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

// [1, N]
int bitx[MAX_N + 1], bity[MAX_N + 1], N;

int sumx(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += bitx[i];
		i -= i & -i;
	}
	return s;
}

int sumy(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += bity[i];
		i -= i & -i;
	}
	return s;
}

void addx(int i, int x)
{
	while (i <= N)
	{
		bitx[i] += x;
		i += i & -i;
	}
}

void addy(int i, int x)
{
	while (i <= N)
	{
		bity[i] += x;
		i += i & -i;
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
		
		addx(i, x)
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

