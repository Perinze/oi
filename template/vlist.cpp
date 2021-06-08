int head[maxn];
int to[maxe];
int cost[maxe];
int nxt[maxe];
int cnt; // 1-ordered

void add(int v, int u, int w)
{
    ++cnt;
    to[cnt] = u;
    cost[cnt] = w;
    nxt[cnt] = head[v];
    head[v] = cnt;
}

// for (int i = head[v]; i; i = nxt[i])

struct edge {
    int v, u, w;
    int next;
} es[maxe];
int head[maxn];
int cnt; // 1-ordered

void add(int v, int u, int w)
{
    es[++cnt] = {v, u, w};
    es[cnt].next = head[v];
    head[v] = cnt;
}