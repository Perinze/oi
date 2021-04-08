#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXV = 510;
const int MAXE = MAXV * MAXV;

struct edge {
    int u, v;
    double w;
    bool operator<(edge s) const { return w < s.w; }
    bool operator>(edge s) const { return w > s.w; }
} es[MAXE];
double x[MAXV], y[MAXV];
int par[MAXV], rnk[MAXV];
bool sat[MAXV];
int S, V, E;

void init()
{
    for (int i = 0; i < V; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y])
        par[x] = y;
    else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

double kruskal()
{
    std::sort(es, es + E);
    init();
    double res = 0.0;
    //for (int i = 0; i < E; i++) {
    int ne = 0, i = 0;
    while (ne < V - S) {
        edge e = es[i++];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res = std::max(res, e.w);
            ne++;
        }
    }
    return res;
}

double dist(int u, int v)
{
    return sqrt((y[u] - y[v]) * (y[u] - y[v]) + (x[u] - x[v]) * (x[u] - x[v]));
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(es, 0, sizeof(es));
        E = 0;

        scanf("%d%d", &S, &V);
        for (int i = 0; i < V; i++) {
            scanf("%lf%lf", x + i, y + i);
            for (int j = i - 1; j >= 0; j--)
                es[E++] = {i, j, dist(i, j)};
        }
        printf("%.2f\n", kruskal());
    }
    return 0;
}