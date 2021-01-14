#include <iostream>
#include <string>
using namespace std;

const int INF = 2000000;
int N;
int a[30000];

void solve()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	int lwr, llwr, hir, lhir;
	llwr = INF, lhir = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] < lhir)
		{
			cout << "NO" << endl;
			return;
		}

		lwr = llwr, hir = a[i] - lwr;
		if (hir < lhir)
		{
			lwr -= lhir - hir;
			hir = lhir;
		}

		llwr = lwr, lhir = hir;
	}
	cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
