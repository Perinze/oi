#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXV = 150;
typedef pair<int, int> P;

int G[MAXV][MAXV];
int d[MAXV];
int V;

void dijkstra()
{
    memset(d, 0x3f, V * sizeof(int));
    d[0] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, 0));
    while (!q.empty())
    {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int u = 0; u < V; u++)
        {
            if (G[v][u] == -1) continue;
            if (d[u] > d[v] + G[v][u])
            {
                d[u] = d[v] + G[v][u];
                q.push(P(d[u], u));
            }
        }
    }
}

int main()
{
    scanf("%d", &V);
    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int num = 0;
            char c;
            while ((c = getchar()) == ' ' || c == '\n');
            if (c == 'x')
            {
                G[i][j] = G[j][i] = -1;
                continue;
            }
            num = c - '0';
            while ((c = getchar()) != ' ' && c != '\n' && c != EOF)
                num = num * 10 + c - '0';
            G[i][j] = G[j][i] = num;
        }
    }
    dijkstra();
    int ans = 0;
    for (int i = 0; i < V; i++)
        ans = max(ans, d[i]);
    printf("%d\n", ans);
    return 0;
}