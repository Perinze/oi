#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
struct st {
	int y0, x0, y1, x1;
	int prv, dir, step;
} Q[maxn * maxn * maxn * maxn];
int L, R;

char mp[2][maxn][maxn];
const int dy[] = {1, 0, 0, -1};
const int dx[] = {0, -1, 1, 0};
const char dc[] = "DLRU";
bool vis[maxn][maxn][maxn][maxn];
char ans[maxn * maxn];

int check(int s, int y, int x)
{
	if (y < 0 || y >= 20) return 1;
	if (x < 0 || x >= 20) return 1;
	if (mp[s][y][x] == '#') return 1;
	return 0;
}

int bfs()
{
	L = R = 0;
	vis[19][19][19][0] = true;
	st crt, nxt;
	crt.y0 = 19, crt.x0 = 19, crt.y1 = 19, crt.x1 = 0;
	crt.prv = -1, crt.step = 0;
	Q[R++] = crt;
	while (L < R) {
		crt = Q[L];
		int y0 = crt.y0, x0 = crt.x0;
		int y1 = crt.y1, x1 = crt.x1;
		int ny0, nx0, ny1, nx1;
		for (int i = 0; i < 4; i++) {
			ny0 = y0 + dy[i], nx0 = x0 + dx[i];
			if (check(0, ny0, nx0)) ny0 = y0, nx0 = x0;
			ny1 = y1 + dy[i], nx1 = x1 - dx[i];
			if (check(1, ny1, nx1)) ny1 = y1, nx1 = x1;

			if (vis[ny0][nx0][ny1][nx1]) continue;
			vis[ny0][nx0][ny1][nx1] = true;
			nxt.y0 = ny0, nxt.x0 = nx0;
			nxt.y1 = ny1, nxt.x1 = nx1;
			nxt.prv = L;
			nxt.dir = i;
			nxt.step = crt.step + 1;

			Q[R] = nxt;
			if (ny0 == 0 && nx0 == 19 && ny1 == 0 && nx1 == 0) {
				return R;
			}
			R++;
		}
		L++;
	}
	return -1;
}

int main()
{
	for (int i = 0; i < 20; i++)
		cin >> mp[0][i] >> mp[1][i];
	int p = bfs();
	cout << Q[p].step << endl;
	do {
		st &crt = Q[p];
		mp[0][crt.y0][crt.x0] = 'A';
		mp[1][crt.y1][crt.x1] = 'A';
		ans[crt.step] = dc[crt.dir];
	} while ((p = Q[p].prv) != -1);
	cout << (ans + 1) << endl;
	for (int i = 0; i < 20; i++)
		cout << mp[0][i] << ' ' << mp[1][i] << endl;
	return 0;
}
