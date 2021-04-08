#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>

namespace io {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') s = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        return x * s;
    }
}

typedef std::pair<int, int> P;
const int MAXV = 30010;
const int MAXE = 150010;

int to[MAXE];
int cost[MAXE];
int nxt[MAXE];
int head[MAXV];
int V, E;

int d[MAXV];

int dijkstra(int s, int t)
{
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P> > q;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = head[v]; i; i = nxt[i]) {
            int u = to[i], w = cost[i];
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push(P(d[u], u));
            }
        }
    }
    return d[t];
}

int main()
{
    V = io::read<int>();
    E = io::read<int>();
    for (int i = 1; i <= E; i++) {
        int u, v, w;
        u = io::read<int>();
        v = io::read<int>();
        w = io::read<int>();
        to[i] = v;
        cost[i] = w;
        nxt[i] = head[u];
        head[u] = i;
    }
    printf("%d\n", dijkstra(1, V));
    return 0;
}