#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define each(i, l, r) for (int i = l; i < r; i++)
using namespace std;
int a, b;
void fun()
{
	a = 100;
	b = 200;
}

void solve()
{
	int a = 5, b = 7;
	fun();
	printf("%d, %d", a, b);
}

int main()
{
	solve();
	cout << "done";
	return 0;
}
