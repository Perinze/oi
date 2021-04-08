#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 150;

bool d[MAXV][MAXV];
int V;

void floyd()
{
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
}

int main()
{
    int E;
    scanf("%d%d", &V, &E);
    while (E--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        d[a][b] = true;
    }
    for (int i = 0; i < V; i++)
        d[i][i] = true;
    floyd();
    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        bool fail = false;
        for (int j = 0; j < V; j++)
            if (!(d[i][j] || d[j][i]))
            {
                fail = true;
                break;
            }
        if (!fail) ans++;
    }
    printf("%d\n", ans);
    return 0;
}