#include <cstdio>
#include <cstring>

const int MAXV = 550, MAXE = 5250; 

struct edge
{
    int from, to, cost;
} es[MAXE];
int d[MAXV];
int V, E;

bool find_negative_loop(int s)
{
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}

int main()
{
    int F;
    scanf("%d", &F);
    while (F--)
    {
        int e, w;
        scanf("%d%d%d", &V, &e, &w);
        E = 0;
        for (int i = 0; i < e; i++)
        {
            int u, v, t;
            scanf("%d%d%d", &u, &v, &t); u--; v--;
            es[E++] = {u, v, t};
            es[E++] = {v, u, t};
        }
        for (int i = 0; i < w; i++)
        {
            int u, v, t;
            scanf("%d%d%d", &u, &v, &t); u--; v--;
            es[E++] = {u, v, -t};
        }
        /*
        bool found = false;
        for (int i = 0; i < V; i++)
        {
            if (find_negative_loop(i))
            {
                found = true;
                break;
            }
        }
        */
        if (find_negative_loop(0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}