#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node
{
	int a, b;
	bool operator <(const node s) { return a < s.a; }
} p[400];

int calc(int n)
{
	int res = 0;
	int i;
	for (i = 0; i < n; i++)
		res += p[i].a;
	int m = 0;
	for (; i < 400; i++)
		m = max(p[i].b, m);

	return max(res, m);
}

int main()
{
	int MAX = 30;
	MAX++;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 400; i++)
	{
		p[i].a = rand() % MAX;
		p[i].b = rand() % MAX;
	}

	sort(p, p + 400);
	int last = -1;
	bool increasing = true;
	for (int i = 0; i < 400; i++)
	{
		if (calc(i) < last)
		{
			increasing = false;
			break;
		}
		last = calc(i);
	}
	cout << increasing << endl;

	return 0;
}
