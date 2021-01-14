#include <iostream>
using namespace std;

// arrays to help mark whether a column, right slash, left slash
// is currently used (queened)
bool used_col[8];
bool used_right[15];
bool used_left[15];

int map[8];

void show()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i] != j) cout << '.';
			else cout << 'o';
		}
		cout << endl;
	}
	cout << endl;
}

int dfs(int y, int x)
// because calling next dfs() with y + 1
// we needn't a used_row[] to mark whether a row is queened
// the return value is the number of solution from putting this queen(in row y)
{
	// examine whether a column, right slash, left slash is queened
	if (used_col[x]) return 0;
	if (used_right[y - x + 7]) return 0;
	if (used_left[y + x]) return 0;
	map[y] = x;

	// if this is the 8-th queen, then I found a new solution
	// return 1 for I found one more solution, then the function exit
	if (y == 7)
	{
		show();
		return 1;
	}

	// otherwise, not the 8-th queen
	// mark that I put one new queen
	// and this column, right slash, left slash is used
	used_col[x] = true;
	used_right[y - x + 7] = true;
	used_left[y + x] = true;

	// calling rest of the function
	// each means that will put a new queen at (y + 1, x)
	// where x is from 0 to 8
	// and use varible res to collect all the solution
	int res = 0;
	for (int x = 0; x < 8; x++)
	{
		res += dfs(y + 1, x);
	}

	// remove the current queen
	// represent that this column, right slash, left slash will not be used
	used_col[x] = false;
	used_right[y - x + 7] = false;
	used_left[y + x] = false;

	// return the number of solution to the father dfs() function which calling me
	return res;
}

void solve()
{
	int res = 0;	// result
	for (int i = 0; i < 8; i++)
	// regard the situations I put the first queen at (0, i)
	// where i is from 0 to 8, respectly
	{
		res += dfs(0, i);
	}
	// output the total number of results
	cout << res << endl;
}

int main()
{
	solve();
	return 0;
}
