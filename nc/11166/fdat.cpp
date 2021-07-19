#include <bits/stdc++.h>
using namespace std;

const int start = 10000;

int main()
{
	int s = 0;
	for (int i = 0; i < start * 10; i++) {
		if (i % 3 == 0) s++;
		if (i >= start && (i + 1) % start == 0) cout << i << ": " << s << endl;
	}
	return 0;
}