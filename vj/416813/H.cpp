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
bool ok = true;

bool read(ll &num)
{
	char c;
	while ((c = cin.get()) == '5'); 
	if (c == EOF) ok = false;
	if (c == EOF || c == '\n') return false;

	num = c - '0';
	while ((c = cin.get()) != EOF && c != '\n' && c != '5')
	{
		num = num * 10 + c - '0';
	}
	if (c == EOF) ok = false;
	if (c == EOF || c == '\n') return false;
	return true;
}

void solve()
{
	vector<ll> a;
	ll num;
	bool status;
	for (;;)
	{
		status = read(num);
		a.push_back(num);
		if (!status)
			break;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while (ok) solve();
	return 0;
}
