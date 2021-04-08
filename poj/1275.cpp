#include <cstdio>
#include <cstring>
#include <cctype>
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

const int MAXN = 1010;

int R[25], t[25];
int N;
int num[25];

int head[25];
int to[100];
int cost[100];
int nxt[100];
int len;

int d[25];
int cnt[25];
int inq[25];

void add(int v, int u, int w)
{
    to[len] = u;
    cost[len] = w;
    nxt[len] = head[v];
    head[v] = len++;
}

bool spfa(int s24)
{
    memset(head, 0, sizeof(head));
    len = 1;
    for (int i = 1; i <= 24; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -num[i]);
        if (i >= 8)
            add(i - 8, i, R[i]);
        else
            add(i + 16, i, -s24 + R[i]);
    }
    add(0, 24, s24);
    add(24, 0, -s24);

    memset(d, -0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    d[0] = 0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inq[v] = false;
        for (int i = head[v]; i; i = nxt[i]) {
            int u = to[i];
            int w = cost[i];
            if (d[u] < d[v] + w) {
                d[u] = d[v] + w;
                cnt[u] = cnt[v] + 1;
                if (cnt[u] >= 25) return true;
                if (!inq[u]) {
                    inq[u] = true;
                    q.push(u);
                }
            }
        }
    }
    return false;
}

int main()
{
    int T = io::read<int>();
    while (T--) {
        for (int i = 1; i <= 24; i++)
            R[i] = io::read<int>();
        N = io::read<int>();
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= N; i++) {
            int k = io::read<int>();
            num[k + 1]++;
        }
        bool found = false;
        for (int i = 1; i <= N; i++) {
            if (!spfa(i)) {
                found = true;
                break;
            }
        }
        if (found) printf("%d\n", d[24]);
        else printf("No Solution\n");
    }
    return 0;
}