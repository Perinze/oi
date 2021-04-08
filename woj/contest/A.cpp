#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

typedef long long ll;

void solve()
{
	string A, B;
	cin >> A;
	cin >> B;

	int t = 0;
	for (int i = 0; i <= A.size() - B.size(); i++)
	{
		//cout << i << "-th comparation" << endl;
		bool found = true;
		int j;
		for (j = 0; j < B.size(); j++)
		{
			//cout << "comparing " << A[i + j] << " and " << B[j] << endl;
			if (A[i + j] != B[j])
			{
				found = false;
			}
		}

		//cout << (found?"found":"not found") << endl;
		if (found)
		{
			t++;
		}
		if (t == 2)
		{
			cout << i + 1 << endl;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
