#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXV = 200;
const float INF = 2000.0;

float x[MAXV], y[MAXV];
float cost[MAXV][MAXV];
float d[MAXV];
bool used[MAXV];
int V;

float dist(int u, int v)
{
    return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

void dijkstra()
{
    memset(used, 0, V * sizeof(bool));
    fill(d, d + V, INF);
    d[0] = 0;
    for (;;)
    {
        int v = -1;
        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; u++)
            if (u != v)
                d[u] = min(d[u], max(d[v], cost[v][u]));
    }
}

int main()
{
    for (int t = 1; ; t++)
    {
        scanf("%d", &V);
        if (V == 0) break;
        for (int i = 0; i < V; i++) scanf("%f%f", x + i, y + i);
        for (int i = 0; i < V; i++)
            for (int j = i; j < V; j++)
                cost[i][j] = cost[j][i] = dist(i, j);
        dijkstra();
        printf("Scenario #%d\n", t);
        printf("Frog Distance = %.3f\n\n", d[1]);
    }
    return 0;
}