#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int par[maxn], rnk[maxn];
int in[maxn], out[maxn];
int in2v[maxn], out2v[maxn];
vector<int> kids[maxn];
int v2bfs[maxn];
int n;
int maxrnk = 0;

int incnt = 0;
int outcnt = 0;
void dfs(int v)
{
    in[v] = ++incnt;
    in2v[in[v]] = v;
    rnk[v] = rnk[par[v]] + 1;
    maxrnk = max(maxrnk, rnk[v]);
    for (int i = 0; i < kids[v].size(); i++) {
        dfs(kids[v][i]);
    }
    out[v] = ++outcnt;
    out2v[out[v]] = v;
}

void bfs()
{
    queue<int> q;
    q.push(1);
    int cnt = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        v2bfs[v] = ++cnt;
        for (int i = 0; i < kids[v].size(); i++) {
            q.push(kids[v][i]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", par + i);
        kids[par[i]].push_back(i);
    }
    rnk[0] = -1;
    dfs(1);
    bfs();
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d %d\n", i, in[i], out[i], v2bfs[i]);
    }
    */
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, d;
        scanf("%d%d", &u, &d);
        if (d > maxrnk) {
            puts("0");
            continue;
        }
        if (rnk[u] > d) {
            puts("0");
            continue;
        }
        int dd = d - rnk[u];
        //printf("dd:%d\n", dd);
        int inn = in[u], outt = out[u];
        //printf("in[u] = %d, out[u] = %d\n", inn, outt);
        inn += dd, outt -= dd;
        while (rnk[in2v[inn]] < d) inn++;
        while (rnk[out2v[outt]] < d) outt--;
        //printf("range in:%d to out:%d\n", inn, outt);
        int l = in2v[inn], r = out2v[outt];
        //printf("vertex %d %d\n", l, r);
        //printf("v2bfs %d %d\n", v2bfs[l], v2bfs[r]);
        int res = v2bfs[r] - v2bfs[l] + 1;
        printf("%d\n", res);
    }
    return 0;
}