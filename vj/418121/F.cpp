#include <cstdio>
#include <cmath>

int N; double D;
int par[1001], rnk[1001];
bool G[1001][1001];
bool on[1001];
double x[1001], y[1001];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
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
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

double dist(int a, int b)
{
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

char gch()
{
    char c;
    for (;;)
    {
        c = getchar();
        if (c == 'S' || c == 'O' || c == EOF) return c;
    }
}

int main()
{
    scanf("%d %lf", &N, &D);
    init(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf %lf", x + i, y + i);
        for (int j = 0; j < i; j++)
        {
            if (dist(i, j) <= D)
            {
                G[i][j] = G[j][i] = true;
                #ifdef DEBUG
                printf("connect %d and %d\n", j, i);
                #endif
            }
        }
    }
    #ifdef DEBUG
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", G[i][j]);
        putchar('\n');
    }
    #endif
    char cmd;
    while ((cmd = gch()) != EOF)
    {
        if (cmd == 'S')
        {
            int a, b;
            scanf("%d %d", &a, &b); a--, b--;
            #ifdef DEBUG
            printf("%d %d\n", a, b);
            printf("%d %d %d\n", on[a], on[b], same(a, b));
            #endif
            if (on[a] && on[b] && same(a, b)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
        else
        {
            int x;
            scanf("%d", &x); x--;
            on[x] = true;
            for (int i = 0; i < N; i++)
            {
                #ifdef DEBUG
                printf("%d %d\n", on[i], G[x][i]);
                #endif
                if (on[i] && G[x][i])
                {
                    unite(x, i);
                    #ifdef DEBUG
                    printf("unite %d %d\n", x, i);
                    for (int i = 0; i < N; i++) printf("%d\t", i); putchar('\n');
                    for (int i = 0; i < N; i++) printf("%d\t", par[i]); putchar('\n');
                    #endif
                }
            }
        }
    }
    return 0;
}
