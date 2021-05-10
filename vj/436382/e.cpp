#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int maxv = 1e4 + 10, maxe = 5e4 + 10;
const int inf = 0x3f3f3f3f;
int v, e, t;

struct edge {
    int c, w, t;
    edge(int c, int w, int t): c(c), w(w), t(t) {}
};
vector<edge> G[maxv];
int d[maxv];

bool dijkstra(int loc)
{
    memset(d, inf, sizeof(d));
    d[1] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, 1));
    while (!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (e.c < loc) continue;
            if (d[e.t] > d[v] + e.w) {
                d[e.t] = d[v] + e.w;
                q.push(P(d[e.t], e.t));
            }
        }
    }
    return d[v] <= t;
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--) {
        cin >> v >> e >> t;
        for (int i = 1; i <= v; i++) G[i].clear();
        int l = 2e9 + 1, r = 0;
        for (int i = 1; i <= e; i++) {
            int a, b, c, w;
            cin >> a >> b >> c >> w;
            G[a].push_back(edge(c, w, b));
            G[b].push_back(edge(c, w, a));
            l = min(l, c);
            r = max(r, c);
        }
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (dijkstra(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}