#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 3e4 + 5;
const int inf = 0x3f3f3f3f;
struct edge {
	int to, w;
} es[maxn];
int head[maxn];
int nxt[maxn];
int len;
int n, k;
int siz[maxn];
int dis[maxn];
int del[maxn];
int cnt;
int ans;

namespace i {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s = 1;
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

int getsize(int u, int p)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = es[i].to;
		if (v == p || del[v]) continue;
		siz[u] += getsize(v, u);
	}
	return siz[u];
}

void getroot(int u, int totsiz, int p, int &lomaxsiz, int &root)
{
	int maxsiz = totsiz - siz[u];
	for (int i = head[u]; i; i = nxt[i]) {
		int v = es[i].to;
		if (v == p || del[v]) continue;
		maxsiz = max(maxsiz, siz[v]);
		getroot(v, totsiz, u, lomaxsiz, root);
	}
	if (maxsiz < lomaxsiz) {
		lomaxsiz = maxsiz;
		root = u;
	}
}

void getdis(int u, int d, int p)
{
	dis[cnt++] = d;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = es[i].to, w = es[i].w;
		if (v == p || del[v]) continue;
		getdis(v, d + w, u);
	}
}

int solve(int u, int d)
{
	cnt = 0;
	getdis(u, d, 0);
	sort(dis, dis + cnt);
	int res = 0;
	int l = 0, r = cnt - 1;
	while (l < r) {
		while (l < r && dis[l] + dis[r] > k) r--;
		res += r - l;
		l++;
	}
	return res;
}

void divcqr(int u)
{
	cnt = 0;
	int lominsiz = inf;
	int root;
	getsize(u, 0);
	getroot(u, siz[u], 0, lominsiz, root);
	ans += solve(root, 0);
	del[root] = 1;
	for (int i = head[root]; i; i = nxt[i]) {
		int v = es[i].to, w = es[i].w;
		if (del[v]) continue;
		ans -= solve(v, w);
		divcqr(v);
	}
}

int main()
{
	for (;;) {
		n = i::read<int>();
		k = i::read<int>();
		if (!n) break;
		memset(del, 0, sizeof(del));
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(es, 0, sizeof(es));
		len = 0;
		ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int u = i::read<int>();
			int v = i::read<int>();
			int w = i::read<int>();
			nxt[++len] = head[u];
			es[len] = edge{v, w};
			head[u] = len;
			nxt[++len] = head[v];
			es[len] = edge{u, w};
			head[v] = len;
		}
		divcqr(1);
		printf("%d\n", ans);
	}
	return 0;
}