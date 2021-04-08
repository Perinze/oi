#include <iostream>
#include <iomanip>
#include <algorithm>
#include <list>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> P;

int read()
{
	char c;
	while ((c = cin.get()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			int num = c - '0';
			while ((c = cin.get()) >= '0' && c <= '9')
			{
				num = num * 10 + c - '0';
			}
			return num;
		}
		if (c == '+') return -1;
		if (c == '-') return -2;
		if (c == '*') return -3;
		if (c == '/') return -4;
		if (c == '\n') return -5;
	}
	return -5;
}

bool solve()
{
	list<double> xp;
	int in;
	while ((in = read()) != -5)
	{
		cout << in << endl;
		xp.push_back(in);
	}
	if (xp.front() == 0.0 && xp.size() == 1) return false;

	for (auto ite = xp.begin(); ite != xp.end(); ite++) cout << *ite << ' ';
	cout << endl;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	while (solve());
	return 0;
}
