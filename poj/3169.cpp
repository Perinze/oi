/*
 * In ML
 * A, B, D
 * A - B <= D && B - A <= D
 * 
 * In MD
 * A, B, D
 * A - B >= D && B - A >= D
 * that is B - A <= -D && A - B <= -D
 */

#include <cstdio>
#include <cctype>
#include <cstring>
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

    char pbuf[1 << 20], *pp = pbuf;
    inline void push(const char &c)
    {
        if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
        *pp++ = c;
    }
    template <typename T>
    inline void write(T x)
    {
        static int s[35];
        int top = 0;
        do {
            s[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(s[--top] + '0');
    }
    inline void flush()
    {
        fwrite(pbuf, 1, pp - pbuf, stdout), pp = pbuf;
    }
}

const int INF = 0x3f3f3f3f;
const int MAXV = 1010;
const int MAXE = 20010;

int head[MAXV];
int to[MAXE];
int cost[MAXE];
int nxt[MAXE];
int len = 1;

int V;

int cnt[MAXV];
int d[MAXV];
bool inq[MAXV];

void add(int v, int u, int w)
{
    to[len] = u;
    cost[len] = w;
    nxt[len] = head[v];
    head[v] = len++;
}

int spfa(int s, int t)
{
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    cnt[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        inq[v] = false;
        for (int i = head[v]; i; i = nxt[i]) {
            int u = to[i];
            int w = cost[i];
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                cnt[u] = cnt[v] + 1;
                if (cnt[u] > V) return -1;
                if (!inq[u]) {
                    q.push(u);
                    inq[u] = true;
                }
            }
        }
    }
    return d[t] == INF ? -2 : d[t];
}

int main()
{
    V = io::read<int>();
    int ml = io::read<int>();
    int md = io::read<int>();
    for (int i = 0; i < ml; i++) {
        int v = io::read<int>(), u = io::read<int>(), w = io::read<int>();
        add(v, u, w);
    }
    for (int i = 0; i < md; i++) {
        int v = io::read<int>(), u = io::read<int>(), w = io::read<int>();
        add(u, v, -w);
    }
    printf("%d\n", spfa(1, V));
    return 0;
}