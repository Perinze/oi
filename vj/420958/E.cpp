#include <cstdio>
#include <cstring>

const int MAXV = 100, MAXE = 200;
struct edge { int from, to; double r, c; } es[MAXE];
double d[MAXV];
int V, E;

double cost(double w, double r, double c)
{
    return (w - c) * r;
}

bool find_positive_loop(int s, double w)
{
    memset(d, 0, sizeof(d));
    d[s] = w;
    for (int j = 0; j < V; j++)
    {
        for (int i = 0; i < E; i++)
        {
            edge e = es[i];
            if (d[e.to] < cost(d[e.from], e.r, e.c))
            {
                d[e.to] = cost(d[e.from], e.r, e.c);
                if (j == V - 1) return true;
            }
        }
    }
    return false;
}

int main()
{
    int s; double w;
    scanf("%d%d%d%lf", &V, &E, &s, &w);
    s--;
    E *= 2;
    for (int i = 0; i < E; i += 2)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        double r, c;
        scanf("%lf%lf", &r, &c);
        es[i] = {u, v, r, c};
        scanf("%lf%lf", &r, &c);
        es[i + 1] = {v, u, r, c};
    }
    printf("%s\n", find_positive_loop(s, w)? "YES": "NO");;
    return 0;
}