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
int n, k;

void solve()
{
	k = 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++) k *= 10;
	string a, b;
	cin >> a >> b;
	vector<P> seq;
	for (int i = 0; i < n; i++)
	{
		seq.push_back(P(a[i], b[i]));
	}
	sort(seq.begin(), seq.end());
	int red = 0, blue = 0;
	do
	{
		for (int i = 0; i < n; i++)
		{
			if (seq[i].first > seq[i].second)
			{
				red++;
				break;
			}
			if (seq[i].first < seq[i].second)
			{
				blue++;
				break;
			}
		}
	} while (next_permutation(seq.begin(), seq.end()));
	if (red > blue) cout << "RED\n";
	else if (red < blue) cout << "BLUE\n";
	else cout << "EQUAL\n";
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve();
	return 0;
}
