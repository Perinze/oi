int head[maxn];
int to[maxe];
int cost[maxe];
int nxt[maxe];
int cnt; // 1-ordered

void add(int v, int u, int w)
{
    to[cnt] = u;
    cost[cnt] = w;
    nxt[cnt] = head[v];
    head[v] = cnt++;
}

// for (int i = head[v]; i; i = nxt[i])