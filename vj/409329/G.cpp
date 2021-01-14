#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

map<char, char> mirror = {
	{'A', 'A'},
	{'B', '0'},
	{'C', '0'},
	{'D', '0'},
	{'E', '3'},
	{'F', '0'},
	{'G', '0'},
	{'H', 'H'},
	{'I', 'I'},
	{'J', 'L'},
	{'K', '0'},
	{'L', 'J'},
	{'M', 'M'},
	{'N', '0'},
	{'O', 'O'},
	{'P', '0'},
	{'Q', '0'},
	{'R', '0'},
	{'S', '2'},
	{'T', 'T'},
	{'U', 'U'},
	{'V', 'V'},
	{'W', 'W'},
	{'X', 'X'},
	{'Y', 'Y'},
	{'Z', '5'},
	{'1', '1'},
	{'2', 'S'},
	{'3', 'E'},
	{'4', '0'},
	{'5', 'Z'},
	{'6', '0'},
	{'7', '0'},
	{'8', '8'},
	{'9', '0'}
};

void solve()
{
	string s;
	while (cin >> s)
	{
		bool palindrome = true, mirrored = true;
		for (int i = 0; i < (s.size() + 1) / 2; i++)
		{
			char l = s[i], r = s[s.size() - i - 1];

			if (l != r)	// not palindrome
			{
				palindrome = false;
			}
			if (l != mirror[r])
			{
				mirrored = false;
			}
			if (!palindrome && !mirrored) break;
		}
		cout << s;
		if (palindrome && mirrored)
		{
			cout << " -- is a mirrored palindrome.";
		}
		else if (palindrome)
		{
			cout << " -- is a regular palindrome.";
		}
		else if (mirrored)
		{
			cout << " -- is a mirrored string.";
		}
		else
		{
			cout << " -- is not a palindrome.";
		}
		cout << endl << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
