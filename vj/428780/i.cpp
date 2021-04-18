#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv = 50010;
const int maxe = 200010;
int n;
int head[maxv]; 
int nxt[maxe];
int to[maxe];
int cnt;

void add(int v, int u)
{
    nxt[cnt] = head[v];
    to[cnt] = u;
    head[v] = cnt++;
}

int divsum(int x)
{
    int sum = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i + x / i;
            if (i * i == x)
                sum -= i;
        }
    }
    return sum;
}

bool used[maxv];
int md, mv;

void dfs(int v, int d)
{
    if (used[v]) return;
    used[v] = true;
    if (d > md)
        md = d, mv = v;
    for (int i = head[v]; i; i = nxt[i]) {
        int u = to[i];
        if (!used[u]) dfs(u, d + 1);
    }
}

int main()
{
    scanf("%d", &n);
    cnt = 1;
    for (int i = 2; i <= n; i++) {
        int ds = divsum(i);
        if (ds < i)
            add(ds, i), add(i, ds);
    }
    #ifdef debug
    printf("%d\n", cnt);
    for (int v = 1; v <= n; v++) {
        for (int i = head[v]; i; i = nxt[i]) {
            int u = to[i];
            printf("%d-%d\n", v, u);
        }
    }
    puts("");
    #endif
    md = 0, mv = 1;
    dfs(1, 0);
    memset(used, 0, sizeof(used));
    md = 0;
    dfs(mv, 0);
    printf("%d\n", md);
    return 0;
}