#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;


const int maxn = 2010;
int S[maxn], T[maxn], D[maxn];
int n;
vector<int> G[maxn];
int dfn[maxn], low[maxn], dfncnt;
int scc[maxn], siz[maxn], sc;
int ins[maxn];
#ifdef STL
stack<int> stk;
#else
int stk[maxn], tp;
#endif

void add_edge(int u, int v)
{
    G[u].push_back(v);
    //printf("%d->%d\n", u, v);
}

void tarjan(int u)
{
    //printf("in tarjan(%d)\n", u);
    low[u] = dfn[u] = ++dfncnt;
    //printf("low[%d] = dfn[%d] = %d\n", u, u, dfncnt);
#ifdef STL
    stk.push(u);
#else
    stk[++tp] = u;
#endif
    ins[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            //printf("low[%d] = min(low[%d], low[%d]) = %d\n", u, u, v, low[u]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
            //printf("low[%d] = min(low[%d], dfn[%d]) = %d\n", u, u, v, low[u]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
#ifdef STL
        while (stk.top() != u) {
            scc[stk.top()] = sc;
            siz[sc]++;
            ins[stk.top()] = false;
            stk.pop();
        }
        scc[stk.top()] = sc;
        siz[sc]++;
        ins[stk.top()] = false;
        stk.pop();
#else
        while (stk[tp] != u) {
            scc[stk[tp]] = sc;
            //printf("scc[%d] = %d\n", stk[tp], sc);
            siz[sc]++;
            ins[stk[tp]] = false;
            --tp;
        }
        scc[stk[tp]] = sc;
        siz[sc]++;
        ins[stk[tp]] = false;
        --tp;
#endif
    }
}

void build_graph()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (min(S[i] + D[i], S[j] + D[j]) > max(S[i], S[j])) {
                add_edge(i, n + j);
                add_edge(j, n + i);
            }
            if (min(S[i] + D[i], T[j]) > max(S[i], T[j] - D[j])) {
                add_edge(i, j);
                add_edge(n + j, n + i);
            }
            if (min(T[i], S[j] + D[j]) > max(T[i] - D[i], S[j])) {
                add_edge(n + i, n + j);
                add_edge(j, i);
            }
            if (min(T[i], T[j]) > max(T[i] - D[i], T[j] - D[j])) {
                add_edge(n + i, j);
                add_edge(n + j, i);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    int h, m;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d", &h, &m);
        S[i] = h * 60 + m;
        scanf("%d:%d", &h, &m);
        T[i] = h * 60 + m;
        scanf("%d", D + i);
    }
    build_graph();
    for (int i = 0; i < n * 2; i++) {
        if (!dfn[i]) tarjan(i);
    }
    /*
    for (int i = 0; i < n * 2; i++) {
        printf("%d: %d, %d\n", i, low[i], dfn[i]);
    }
    */
    for (int i = 0; i < n; i++) {
        if (scc[i] == scc[n + i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
        int s, t;
        if (scc[i] < scc[n + i]) {
            s = S[i], t = S[i] + D[i];
        } else {
            s = T[i] - D[i], t = T[i];
        }
        printf("%02d:%02d %02d:%02d\n", s / 60, s % 60, t / 60, t % 60);
    }
    return 0;
}