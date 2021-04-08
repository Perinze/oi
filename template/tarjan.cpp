
int dfn[MAXV];
int low[MAXV];

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
}