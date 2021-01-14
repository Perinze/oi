#include <iostream>
#include <string>
using namespace std;

string dfs(string in, string pr)
{
	// leaf
	if (in.size() <= 1)
	{
		return in;
	}

	// root
	char root = pr[0];
	int rpos = in.find_first_of(root);

	// left
	int left_size = rpos;
	string lin, lpr, lans;

	lin = in.substr(0, left_size);
	lpr = pr.substr(1, left_size);

	lans = dfs(lin, lpr);

	// right
	int right_size = in.size() - rpos - 1;
	string rin, rpr, rans;

	rin = in.substr(rpos+1, right_size);
	rpr = pr.substr(rpos+1, right_size);

	rans = dfs(rin, rpr);
	
	// return
	return lans + rans + root;
}

int main()
{
	ios::sync_with_stdio(false);
	string inor, pre;
	cin >> inor >> pre;
	cout << dfs(inor, pre);
	return 0;
}
