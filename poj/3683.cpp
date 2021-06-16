#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2010;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
int cmp[maxn];
bool vis[maxn];
int S[maxn], T[maxn], D[maxn];
int n;

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
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

void dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (!vis[u]) dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    vis[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        int u = rG[v][i];
        if (!vis[u]) rdfs(u, k);
    }
}

int scc()
{
    memset(vis, 0, sizeof(vis));
    for (int v = 0; v < n; v++) {
        if (!vis[v]) dfs(v);
    }
    memset(vis, 0, sizeof(vis));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!vis[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
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
    scc();
    for (int i = 0; i < n; i++) {
        if (cmp[i] == cmp[n + i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
        int s, t;
        if (cmp[i] > cmp[n + i]) {
            s = S[i], t = S[i] + D[i];
        } else {
            s = T[i] - D[i], t = T[i];
        }
        printf("%02d:%02d %02d:%02d\n", s / 60, s % 60, t / 60, t % 60);
    }
    return 0;
}