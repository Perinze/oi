#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <vector>

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
        T x = 0, s= 1;
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

const int MAXN = 50010;
int N;

int head[MAXN];
int to[MAXN << 2];
int cost[MAXN << 2];
int nxt[MAXN << 2];
int cnt = 1;

bool inq[MAXN];
int d[MAXN];

inline void add(int v, int u, int w)
{
    to[cnt] = u;
    cost[cnt] = w;
    nxt[cnt] = head[v];
    head[v] = cnt++;
}

int spfa(int s, int t)
{
    memset(d, -0x3f, sizeof(d));
    d[s] = 0;
    std::queue<int> q;
    q.push(s);
    inq[s] = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        inq[v] = false;
        for (int i = head[v]; i; i = nxt[i]) {
            int u = to[i];
            int w = cost[i];
            if (d[u] < d[v] + w) {
                d[u] = d[v] + w;
                if (!inq[u]) {
                    q.push(u);
                    inq[u] = true;
                }
            }
        }
    }
    return d[t];
}

int main()
{
    for (int i = 1; i <= 50001; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    N = io::read<int>();
    for (int i = 1; i <= N; i++) {
        int v = io::read<int>();
        int u = io::read<int>() + 1;
        int w = io::read<int>();
        add(v, u, w);
    }
    printf("%d\n", spfa(0, 50001));
    return 0;
}