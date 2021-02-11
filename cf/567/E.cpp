#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 100000, MAXE = 100000;
typedef pair<int, int> P;

struct edge {
    int s, t, w;
};
edge es[MAXE];

vector<edge*> G[MAXV];
vector<edge*> rG[MAXV];
int ds[MAXV];
int dt[MAXV];
int cnts[MAXV];
int cntt[MAXV];
int V, E;
int S, T;

void dijkstra(vector<edge*> &G, int &d[], int &cnt[], int s)
{
    priority_queue<P, vector<P>, greater<P> > q;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    cnt[s] = 1;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (p.first == d[v])
            cnt[v]++;
        if (p.first >= d[v])
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v].t;
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &V, &E, &S, &T);
    S--;
    T--;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        scanf("%d%d%d", &s, &t, &w);
        es[i] = {s, t, w};
        G[s].push_back(es + i);
        rG[t].push_back(es + i);
    }
}