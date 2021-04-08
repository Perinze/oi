#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 2e15;
int N;
struct node
{
	ll a, b;	// a for delivery, b for self taking
	bool operator <(const node s)
	{
		//if (b == s.b) return a > s.a;
		//return b < s.b;
		return a < s.a;
	}
} p[200000];

ll calc(int n)
{
	ll delivery;
	if (n) delivery = p[n-1].a;
	else delivery = 0;
	ll self = 0;
	for (int i = n; i < N; i++)
	{
		self += p[i].b;
	}
	return max(delivery, self);
}

short roc(int i)	// -1 for increasing, 0 for lowest, 1 for decreasing, 2 for const?
{
	//cout << "roc(" << i << ")\n";
	int left, self, right;
	if (i > 0)
	{
		left = calc(i-1);
		//cout << left << ' ';
	}
	self = calc(i);
	//cout << self << ' ';
	if (i < N)
	{
		right = calc(i+1);
		//cout << right << ' ';
	}
	//cout << endl;

	if (i == 0)
	{
		//cout << "if (i == 0)\n";
		//cout << "return " << (self < right ? 0 : 1) << endl;
		if (self < right) return 0;
		return 1;
	}
	if (i == N)
	{
		//cout << "if (i == N)\n";
		//cout << "return " << (self < left ? 0 : -1) << endl;
		if (self < left) return 0;
		return -1;
	}
	//cout << "else\n";
	//if (self < right && self < left) cout << "self < left and right, return 0" << endl;
	if (self < right && self < left) return 0;
	//if (self > left) cout << "self > left, return -1" << endl;
	if (self > left) return -1;
	//if (self > right) cout << "self > right, return 1" << endl;
	if (self > right) return 1;
	return 2;
}

int binary_search(int l, int r)	// [l, r)
{
	//cout << "binary_search(" << l << ", " << r << ")\n";
	if (l == r - 1)
	{
		//cout << "return " <<  (calc(l) < calc(r) ? l : r) << endl;
		return calc(l) < calc(r) ? l : r;
	}
	int m = (l + r) / 2;
	//cout << "m = " << m << endl;
	//if (roc(m) == 0) cout << "roc(m) == 0, return " << m << endl;
	if (roc(m) == 0) return m;
	//if (roc(m) == -1) cout << "roc(m) == -1, calling binary_search(" << l << ", " << m << endl;
	if (roc(m) == -1) return binary_search(l, m);
	//if (roc(m) == 1) cout << "roc(m) == 1, calling binary_search(" << m << ", " << r << endl;
	if (roc(m) == 1) return binary_search(m, r);
	return min(binary_search(l, m), binary_search(m, r));
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].a;
	for (int i = 0; i < N; i++) cin >> p[i].b;

	sort(p, p + N);
	//for (int i = 0; i <= N; i++) cout << calc(i) << ' ';
	//cout << endl;

	int p = binary_search(0, N);
	cout << calc(p) << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		solve();
	}
	return 0;
}
