#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 310;
const int INF = 0x3f3f3f3f;

int C[MAXV][MAXV];
int d[MAXV];
bool inq[MAXV];
int V;

void spfa(int s)
{
	memset(inq, 0, sizeof(inq));
	queue<int> q;
	for (int u = 0; u < V; u++) {
		if (u == s) {
			d[u] = INF;
		} else {
			d[u] = C[s][u];
			q.push(u);
			inq[u] = true;
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		inq[v] = false;
		for (int u = 0; u < V; u++) {
			if (d[u] > d[v] + C[v][u]) {
				d[u] = d[v] + C[v][u];
				if (!inq[u]) {
					q.push(u);
					inq[u] = true;
				}
			}
		}
	}
}

int main()
{
	while (~scanf("%d", &V)) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				scanf("%d", C[i] + j);
			}
		}
		spfa(0);
		int res = d[V - 1];
		int s1 = d[0];
		spfa(V - 1);
		int s2 = d[V - 1];
		printf("%d\n", min(res, s1 + s2));
	}
	return 0;
}