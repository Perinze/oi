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
int ary[3000];

void solve()
{
	for (int i = 0; i < N; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < N; j++)
			if (ary[j] < ary[min_pos])
				min_pos = j;
		cout << i << ' ' << min_pos << endl;
		swap(ary[i], ary[min_pos]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}
	cout << N << endl;
	solve();
	return 0;
}
