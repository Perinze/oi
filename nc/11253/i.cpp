#include <bits/stdc++.h>
using namespace std;

char mp[2][25][25];
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
bool vis[2][25][25];
bool win1, win2;
bool win;
int ans = 0x3f3f3f3f;

bool stop0(int y1, int x1) {
	if (mp[0][y1][x1] == '#') return true;
	if (y1 >= 20 || y1 < 0) return true;
	if (x1 >= 20 || x1 < 0) return true;
	return false;
}
bool stop1(int y1, int x1) {
	if (mp[1][y1][x1] == '#') return true;
	if (y1 >= 20 || y1 < 0) return true;
	if (x1 >= 20 || x1 < 0) return true;
	return false;
}

void dfs(int y1, int x1, int y2, int x2, int d)
{
	if (d > 27) return;
	for (int i = 0; i < 4; i++) {
		int ny1 = y1 + dy[i];
		int ny2 = y2 + dy[i];
		int nx1 = x1 + dx[i];
		int nx2 = x2 - dx[i];
		if (ny1 == 0 && nx1 == 19) win1 = true;
		if (ny2 == 0 && nx2 == 0) win2 = true;
		if (win1 && win2) {
			ans = min(ans, d);
		}
		if (vis[0][ny1][nx1] && vis[1][ny2][nx2]) continue;
		if (stop0(ny1, nx1) && stop1(ny2, nx2)) continue;
		if (stop0(ny1, nx1)) {
			ny1 = y1;
			nx1 = x1;
		}
		if (stop1(ny2, nx2)) {
			ny2 = y2;
			nx2 = x2;
		}
		vis[0][ny1][nx1] = true;
		vis[1][ny2][nx2] = true;
		dfs(ny1, nx1, ny2, nx2, d + 1);
		vis[0][ny1][nx1] = false;
		vis[1][ny2][nx2] = false;
		if (ny1 == 0 && nx1 == 19) win1 = true;
		if (ny2 == 0 && nx2 == 0) win2 = true;
	}
}

int main()
{
	for (int i = 0; i < 20; i++) {
		scanf("%s", mp[0][i]);
		scanf("%s", mp[1][i]);
	}
	win1 = false, win2 = false;
	dfs(19, 19, 19, 0, 0);
	cout << ans << endl;
}