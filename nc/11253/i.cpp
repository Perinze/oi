#include <bits/stdc++.h>
using namespace std;

using pair<int, int> = pii;

char mp[2][25][25];
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
bool vis[25][25][25][25];
bool win0 = false, win1 = false;

int main()
{
	for (int i = 0; i < 20; i++) {
		scanf("%s", mp[0][i]);
		scanf("%s", mp[1][i]);
	}
	dfs(19, 19, 19, 0, 0);
	return 0;
}