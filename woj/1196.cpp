#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;

void solve()
{
	srand(time(NULL));
	cout << rand() % 10 + 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
