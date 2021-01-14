#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
const int MAX_N = 2e5;

// [1, N]
int bit[MAX_N + 1], N;
int ed;

int sum(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x)
{
	while (i <= N)
	{
		bit[i] += x;
		i += i & -i;
	}
}

inline int get(int i)
{
	return sum(i) - sum(i - 1);
}

void swap(int a, int b)
{
	int da, db;
	da = get(b) - get(a);
	db = -da;
	add(a, da);
	add(b, db);
}

void next_permutation()
{
	int p1, p2;	// p1 > p2
	p1 = ed;
	for (p2 = p1 - 1; p2 > 0; p2--)
	{
		if (get(p2) < get(p1))
		{
			swap(p2, p1);
		}
	}
}

void query()
{
	int q; cin >> q;
	if (q == 1)
	{
		int l, r;
		cin >> l >> r;
		cout << sum(r) - sum(l - 1) << endl;
	}
	else
	{
		int t;
		cin >> t;
		for (int i = 0; i < t; i++)
			next_permutation();
	}
	for (int i = 1; i <= N; i++)
	{
		cout << get(i) << ' ';
	}
	cout << endl;
}

void init()
{
	bit[0] = 0;
	for (int i = 1; i <= N; i++) add(i, i);
	ed = N;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> N >> T;
	init();
	for (int t = 0; t < T; t++) query();
	return 0;
}
