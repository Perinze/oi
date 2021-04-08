#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const int MAXV = 100010;
const int MAXE = 100010;

int s[MAXE];
int t[MAXE];
ll w[MAXE];
int nxt[MAXE];
int rnxt[MAXE];

int head[MAXV];
int rhead[MAXV];
int len = 1;

ll ds[MAXV];
ll dt[MAXV];

int dfn[MAXV];
int low[MAXV];
bool del[MAXE];
bool brg[MAXE];
int cnt = 1;

int V, E, S, T;

void add_edge(int u, int v, ll w_)
{
    s[len] = u;
    t[len] = v;
    w[len] = w_;
    nxt[len] = head[u];
    rnxt[len] = rhead[v];
    head[u] = len;
    rhead[v] = len;
    len++;
}

void dijkstra(int s, int *to, int *nxt, int *head, ll *d)
{
    memset(d, 0x3f, (V + 1) * sizeof(ll));
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = head[v]; i != 0; i = nxt[i]) {
            int u = to[i];
            if (d[u] > d[v] + w[i]) {
                d[u] = d[v] + w[i];
                q.push(P(d[u], u));
            }
        }
    }
}

void remove()
{
    for (int i = 1; i <= E; i++) {
        if (ds[s[i]] + w[i] + dt[t[i]] != ds[T])
            del[i] = true;
    }
}

void tarjan(int v, int par)
{
    dfn[v] = low[v] = cnt++;
    for (int i = head[v]; i != 0; i = nxt[i]) {
        if (del[i]) continue;
        int u = t[i];
        if (!dfn[u]) {
            tarjan(u, i);
            low[v] = min(low[v], low[u]);
            if (dfn[v] < low[u])
                brg[i] = true;
        } else {
            if (par != i)
                low[v] = min(low[v], dfn[u]);
        }
    }
    for (int i = rhead[v]; i != 0; i = rnxt[i]) {
        if (del[i]) continue;
        int u = s[i];
        if (!dfn[u]) {
            tarjan(u, i);
            low[v] = min(low[v], low[u]);
            if (dfn[v] < low[u])
                brg[i] = true;
        } else {
            if (par != i)
                low[v] = min(low[v], dfn[u]);
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &V, &E, &S, &T);
    for (int i = 1; i <= E; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w);
    }
    dijkstra(S, t, nxt, head, ds);
    dijkstra(T, s, rnxt, rhead, dt);
    /*
    for (int i = 1; i <= V; i++)
        printf("%d ", ds[i]);
    printf("\n");
    for (int i = 1; i <= V; i++)
        printf("%d ", dt[i]);
    printf("\n");
    */

    remove();
    tarjan(S, 0);
    /*
    for (int i = 1; i <= V; i++)
        printf("%d %d\n", dfn[i], low[i]);
    */
    for (int i = 1; i <= E; i++) {
        if (!del[i] && brg[i])
            printf("YES\n");
        else {
            ll crt = ds[s[i]] + w[i] + dt[t[i]];
            if (crt - ds[T] + 1 < w[i])
                printf("CAN %lld\n", crt - ds[T] + 1);
            else
                printf("NO\n");
        }
    }
    return 0;
}