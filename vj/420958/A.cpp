#include <cstdio>
#include <cstring>

const int MAXV = 1000, MAXE = 4000, INF = 0x3f3f3f3f;
struct edge { int from, to, cost; };

edge es[MAXE];

int d[MAXV];
int V, E;

void shortest_path(int s)
{
    memset(d, 0x3f, V * sizeof(int));
    d[s] = 0;
    for (;;)
    {
        bool update = false;
        for (int i = 0; i < E; i++)
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main()
{
    scanf("%d%d", &E, &V);
    E *= 2;
    for (int i = 0; i < E; i += 2)
    {
        edge &e = es[i];
        scanf("%d%d%d", &e.from, &e.to, &e.cost);
        e = {e.from - 1, e.to - 1, e.cost};
        es[i + 1] = {e.to, e.from, e.cost};
    }
    shortest_path(V - 1);
    printf("%d\n", d[0]);
    return 0;
}