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

int N;
int a[10];

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void sort()
{
	int total = 0;
	for (;;)
	{
		int t = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				cout << i << ' ' << i + 1 << endl;
				swap(a[i], a[i + 1]);
				t++;
			}
		}
		if (t == 0) break;
		total += t;
	}
	//cout << total << endl;
}

int getk()
{
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i]) ans++;
		}
	}
	return ans;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cout << getk() << endl;
	sort();
	/*
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << ' ';
	}
	*/
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
