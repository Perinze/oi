#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

const int BUF = 100;
const int MAXN = 10000 + BUF;
const int MAXV = 2 * MAXN;
const int MAXE = 4 * MAXN;

int N, M;
double ax, ay, bx, by, cx, cy, dx, dy;

int par[MAXV], rk[MAXV];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rk[x] < rk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

struct vertex
{
    double x, y;
    int id;
} line1[MAXN], line2[MAXN];
int size1, size2;

int V, E;
struct edge
{
    int u, v;
    double d;
} es[MAXE];

bool cmp0(const vertex &v1, const vertex &v2)
{
    if (v1.x == v2.x) return v1.y < v2.y;
    return v1.x < v2.x;
}

bool cmp(const edge &e1, const edge &e2)
{
    return e1.d < e2.d;
}

void ln(int u, int v, double d)
{
    es[E++] = {u, v, d};
}

double dist(const vertex &a, const vertex &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double kruskal()
{
    sort(es, es + E, cmp);
    init(size1 + size2);
    double res = 0.0;
    for (int i = 0; i < E; i++)
    {
        edge e = es[i];
        if (!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.d;
        }
    }

    return res;
}

void solve(int case_id)
{
    size1 = 0, size2 = 0, V = 0, E = 0;

    scanf("%d%d", &N, &M);
    scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
    scanf("%lf%lf%lf%lf", &cx, &cy, &dx, &dy);

    set<double> s;
    for (int i = 0; i < N; i++)
    {
        double t;
        scanf("%lf", &t);
        if (s.find(t) != s.end()) continue;
        s.insert(t);
        double x = ax * t + bx * (1.0 - t);
        double y = ay * t + by * (1.0 - t);
        line1[size1++] = {x, y, V++};
    }
    s.clear();
    for (int i = 0; i < M; i++)
    {
        double t;
        scanf("%lf", &t);
        if (s.find(t) != s.end()) continue;
        s.insert(t);
        double x = cx * t + dx * (1.0 - t);
        double y = cy * t + dy * (1.0 - t);
        line2[size2++] = {x, y, V++};
    }

    sort(line1, line1 + size1, cmp0);
    sort(line2, line2 + size2, cmp0);
    for (int i = 0; i < size1 - 1; i++)
        ln(line1[i].id, line1[i + 1].id, dist(line1[i], line1[i + 1]));
    for (int i = 0; i < size2 - 1; i++)
        ln(line2[i].id, line2[i + 1].id, dist(line2[i], line2[i + 1]));
    for (int i = 0; i < size1; i++)
    {
        int l = 0, r = size2 - 1;
        int lmid, rmid;
        while (r - l > 2)
        {
            lmid = l + (r - l) / 3;
            rmid = r - (r - l) / 3;
            if (dist(line1[i], line2[lmid]) < dist(line1[i], line2[rmid]))
                r = rmid;
            else
                l = lmid;
        }
        ln(line1[i].id, line2[l].id, dist(line1[i], line2[l]));
        ln(line1[i].id, line2[r].id, dist(line1[i], line2[r]));
        ln(line1[i].id, line2[lmid].id, dist(line1[i], line2[lmid]));
        ln(line1[i].id, line2[rmid].id, dist(line1[i], line2[rmid]));
    }

    printf("Case #%d: %.3lf\n", case_id, kruskal());
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) solve(t);
    return 0;
}