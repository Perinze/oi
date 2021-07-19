
int dfn[maxn], low[maxn], dfncnt;
int stk[maxn], top;
bool ins[maxn];
int scc[maxn], siz[maxn], sc;

void tarjan(int u)
{
    low[u] = dfn[u] = ++dfncnt;
    stk[++tp] = u, ins[u] = true;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        do {
            scc[s[tp]] = sc;
            siz[sc]++;
            ins[s[tp]] = false;
            --tp;
        } while (s[tp] != u);
    }
}