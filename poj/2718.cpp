#include <cstdio>
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
int digits[10];

int read(int &x)
{
	x = 0;
	char c;
	while ((c = getchar()) != ' ')
	{
		if (c == EOF || c == '\n') return 1;

		if (c >= '0' && c <= '9')
		{
			x = c - '0' + x * 10;
		}
	}
	return 0;
}

void readline()
{
	int x;
	for (N = 0; ; N++)
	{
		int exit = read(x);
		digits[N] = x;
		if (exit) break;
	}
	N++;
}

vector<int> res;
int left_[10], left_size;
int right_[10], right_size;
bool used[10];

void dfs_add(int x, int l, int num)
{
	//printf("dfs_add(%d, %d, %d)\n", x, l, num);
	if (l == left_size - 1)
	{
		for (int i = 0; i < left_size; i++)
		{
			if (!used[i])
			{
				res.push_back(num);
				//printf("%d\n", num);
				return;
			}
		}
	}

	used[x] = true;
	for (int i = 0; i < left_size; i++)
	{
		if (!used[i])
		{
			dfs_add(i, l + 1, num * 10 + left_[i]);
		}
	}
	used[x] = false;
}

void solve()
{
	readline();
	for (int i = 1; i < (1 << N) - 1; i++)
	{
		left_size = 0;
		right_size = 0;
		for (int j = 0; j < N; j++)
		{
			memset(used, 0, sizeof(used));
			if (i >> j & 1)
			{
				left_[left_size++] = digits[j];
			}
			else
			{
				right_[right_size++] = digits[j];
			}
		}

		//printf("left_size: %d\n", left_size);
		for (int i = 0; i < left_size; i++)
		{
			dfs_add(i, 0, left_[i]);
		}

		for (int i = 0; i < res.size(); i++)
		{
			printf("%d ", res[i]);
		}

		putchar('\n');
		putchar('\n');
	}
}

int main()
{
	int T;
	read(T);
	while (T--)
		solve();
	return 0;
}
