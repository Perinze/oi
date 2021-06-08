#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int maxn = 10010;
const int inf = 2;
struct edge { int to, cap, rev; };
bool has_char[9][maxn];
bool vis[maxn];
int m, n;
//vector<edge> G[maxn * 9];
vector<int> G[maxn * 9];

void addedge(int from, int to)
{
    //G[from].push_back(edge{to, 1, G[to].size()});
    //G[to].push_back(edge{from, 0, G[from].size() - 1});
    //clog << from << " -> " << to << endl;
    G[from].push_back(to);
}

/*
int dfs(int v, int t, int f)
{
    if (v == t) return f;
    for (int i = 1; i <= 7; i++)
        vis[v + i * n] = true;
    for (edge &e : G[v]) {
        if (!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
*/

bool dfs(int v, int t)
{
    //cout << v << ": " << v / n << ", " << v % n << endl;
    if (v == t) return true;
    for (int i = 1; i <= 7; i++)
        vis[v + i * n] = true;
    for (int u : G[v]) {
        if (!vis[u]) {
            if (dfs(u, t)) {
                return true;
            }
        }
    }
    for (int i = 1; i <= 7; i++)
        vis[v + i * n] = false;
    return false;
}

bool maxflow(int s, int t)
{
    if (dfs(s, t)) return true;
    return false;
}

void solve()
{
    ios::sync_with_stdio(false);
    cin >> m;
    string tmp;
    vector<int> vaild_node[9];
    n = 1;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        bool vaild = false;
        for (char c : tmp) {
            switch (c) {
                case 'a':
                case 'A':
                if (!has_char[1][n]) vaild_node[1].push_back(n);
                has_char[1][n] = true;
                vaild = true;
                break;

                case 'c':
                case 'C':
                if (!has_char[2][n]) vaild_node[2].push_back(n);
                has_char[2][n] = true;
                vaild = true;
                break;

                case 'm':
                case 'M':
                if (!has_char[3][n]) vaild_node[3].push_back(n);
                has_char[3][n] = true;
                vaild = true;
                break;

                case '@':
                if (!has_char[4][n]) vaild_node[4].push_back(n);
                has_char[4][n] = true;
                vaild = true;
                break;

                case 'w':
                case 'W':
                if (!has_char[5][n]) vaild_node[5].push_back(n);
                has_char[5][n] = true;
                vaild = true;
                break;

                case 'u':
                case 'U':
                if (!has_char[6][n]) vaild_node[6].push_back(n);
                has_char[6][n] = true;
                vaild = true;
                break;

                case 't':
                case 'T':
                if (!has_char[7][n]) vaild_node[7].push_back(n);
                has_char[7][n] = true;
                vaild = true;
                break;
            }
        }
        if (vaild) n++;
    }
    vaild_node[0].push_back(0);
    vaild_node[8].push_back(n);
    /*
    for (int i = 0; i <= 8; i++) {
        for (int v : vaild_node[i]) {
            clog << v << ' ';
        }
        clog << endl;
    }
    */
    for (int i = 0; i <= 7; i++) {
        for (int a : vaild_node[i]) {
            for (int b : vaild_node[i + 1]) {
                addedge(a + i * n, b + (i + 1) * n);
            }
        }
    }
    if (maxflow(0, 9 * n)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}


#if defined (__i386__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned long long int x;
    __asm__ volatile("rdtsc": "=A"(x));
    return x;
}
#elif defined (__x86_64__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned hi, lo;
    __asm__ volatile("rdtsc": "=a"(lo), "=d"(hi));
    return ((unsigned long long) lo) | (((unsigned long long) hi) << 32);
}
#endif

//#define FREQUENCY 3593.0000
#define FREQUENCY 3590000000

int main()
{
    unsigned long t1, t2;
    t1 = (unsigned long)GetCycleCount();
    solve();
    //usleep(1000000);
    t2 = (unsigned long)GetCycleCount();
    printf("test1: %f\n", (t2 - t1) * 1.0 / FREQUENCY);
}