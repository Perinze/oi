#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

typedef long long ll;
typedef pair<int, int> P;
int N, M;
char board[10][10];
int fire_time[10][10];
bool used[10][10];

char gch()
{
	char c;
	while (cin >> c)
	{
		if (c == '.' || c == '#') return c;
	}
	return '?';
}

bool in_range(int i, int j)
{
	return (i >= 0 && i < N && j >= 0 && j < M);
}

#ifdef DEBUG
void print_fire_time()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << fire_time[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void print_board()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << endl;
}
#endif

int get_min_time(int i, int j)
{
	//cout << "get_min_time(" << i << ", " << j << ")\n";
	if (board[i][j] == '.') return INF;
	queue<P> q, Q;
	memset(used, 0, sizeof(used));
	q.push(P(i, j));
	Q.push(P(i, j));
	used[i][j] = true;
	while (!q.empty())
	{
		P p = q.front(); q.pop();
		//cout << "poping (" << p.first << ", " << p.second << ")\n";
		for (int k = 0; k < 4; k++)
		{
			int ny = p.first + dy[k], nx = p.second + dx[k];
			if (!in_range(ny, nx)) continue;
			if (used[ny][nx]) continue;
			if (board[ny][nx] == '.') continue;
			q.push(P(ny, nx));
			Q.push(P(ny, nx));
			used[ny][nx] = true;
		}
	}

	int ans = INF;
	while (!Q.empty())
	{
		int t = 0;
		memset(fire_time, -1, sizeof(fire_time));
		P s = Q.front(); Q.pop();
		fire_time[s.first][s.second] = 0;
		q.push(s);
		while (!q.empty())
		{
			P p = q.front(); q.pop();
			for (int k = 0; k < 4; k++)
			{
				int ny = p.first + dy[k], nx = p.second + dx[k];
				if (!in_range(ny, nx)) continue;
				if (fire_time[ny][nx] != -1 || board[ny][nx] == '.') continue;
				fire_time[ny][nx] = fire_time[p.first][p.second] + 1;
				t = max(t, fire_time[ny][nx]);
				q.push(P(ny, nx));
			}
		}
		ans = min(ans, t);
	}
	return ans;
}

void update(int nmin, int &min1, int &min2)
{
	if (nmin > min1 && nmin > min2) return;
	int *bigger = &min1;
	if (min2 > min1) bigger = &min2;
	*bigger = nmin;
}

void fire(int i, int j)
{
	if (board[i][j] == '.') return;
	queue<P> q;
	memset(used, 0, sizeof(used));
	q.push(P(i, j));
	used[i][j] = true;
	board[i][j] = '.';
	while (!q.empty())
	{
		P p = q.front(); q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ny = p.first + dy[k], nx = p.second + dx[k];
			if (!in_range(ny, nx)) continue;
			if (used[ny][nx]) continue;
			if (board[ny][nx] == '.') continue;
			used[ny][nx] = true;
			board[ny][nx] = '.';
			q.push(P(ny, nx));
		}
	}
}

int can_fire;
int scan()
{
	int min1 = INF, min2 = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			//cout << "scan to " << i << ", " << j << endl;
			int nmin = get_min_time(i, j);
			//cout << "get_min_time() = " << nmin << endl;
			update(nmin, min1, min2);
			//cout << "mins: " << min1 << ' ' << min2 << endl;
			if (board[i][j] == '#' && can_fire)
			{
				fire(i, j);
				//cout << "fired" << endl;
				can_fire--;
				//print_board();
			}
			if (board[i][j] == '#') return -1;
		}
	if (max(min1, min2) == INF) return min(min1, min2);
	return max(min1, min2);
}

void solve(int t)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			board[i][j] = gch();
			//cout << "board[" << i << "][" << j << "] = " << board[i][j] << endl;
		}
	can_fire = 2;
	cout << "Case " << t << ": " << scan() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++) solve(t + 1);
	return 0;
}
