#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAXV = 1010;
const int MAXE = 1010;

int t[MAXE];
int s[MAXE];
int nxt[MAXE];
int rnxt[MAXE];
int head[MAXV];
int rhead[MAXV];
int len;
int V, E;
int dfn[MAXV], low[MAXV];
int cnt;
int degree[MAXV];

void add_edge(int v, int u)
{
    t[len] = u;
    s[len] = v;
    nxt[len] = head[v];
    rnxt[len] = rhead[u];
    head[v] = len;
    rhead[u] = len;
    len++;
}

void tarjan(int v, int par)
{
    dfn[v] = low[v] = cnt++;
    for (int i = head[v]; i != 0; i = nxt[i]) {
        int u = t[i];
        if (!dfn[u]) {
            tarjan(u, i);
            low[v] = min(low[v], low[u]);
        } else
            if (par != i)
                low[v] = min(low[v], dfn[u]);
    }
    for (int i = rhead[v]; i != 0; i = rnxt[i]) {
        int u = s[i];
        if (!dfn[u]) {
            tarjan(u, i);
            low[v] = min(low[v], low[u]);
        } else
            if (par != i)
                low[v] = min(low[v], dfn[u]);
    }
}

int main()
{
    scanf("%d%d", &V, &E);
    memset(t, 0, (E + 1) * sizeof(int));
    memset(nxt, 0, (E + 1) * sizeof(int));
    memset(head, 0, (V + 1) * sizeof(int));
    len = 1;
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    memset(dfn, 0, (V + 1) * sizeof(int));
    memset(low, 0, (V + 1) * sizeof(int));
    cnt = 1;
    tarjan(1, 0);
    /*
    for (int i = 1; i <= V; i++)
        printf("%d %d %d\n", i, dfn[i], low[i]);
    */

    memset(degree, 0, (V + 1) * sizeof(int));
    for (int v = 1; v <= V; v++) {
        for (int i = head[v]; i != 0; i = nxt[i]) {
            int u = t[i];
            if (low[v] != low[u])
                degree[low[v]]++;
        }
        for (int i = rhead[v]; i != 0; i = rnxt[i]) {
            int u = s[i];
            if (low[v] != low[u])
                degree[low[v]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= V; i++) {
        //printf("%d ", degree[i]);
        if (degree[i] == 1)
            ans++;
    }
    //printf("\n");
    printf("%d\n", (ans + 1) / 2);
    return 0;
}