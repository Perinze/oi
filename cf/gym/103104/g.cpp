#include <bits/stdc++.h>
using namespace std;

const int maxs = 510;
const int maxn = 1010;
const int maxword = 510;
const int maxline = 2010;
char tmp[maxline];

int H, W, N, M;
int n;
vector<int> G[maxn * 2];
int mp[maxs][maxs]; // -1 wall, 0 blank, >= 1 begin marks
int begin_x[maxn], begin_y[maxn]; // 0-ordered
int label[maxn];
int choice[maxn];
char str[maxn][2][maxword];

void add_edge(int u, int v)
{
    G[u].push_back(v);
}

inline int getv(int u, bool c)
{
    return c ? u : u + n;
}

void build_graph()
{
    for (int i = 0; i < N; i++) {
        if (choice[i] == 1) {
            add_edge(n + i, i);
        }
        for (int ih = 0; ih < choice[i]; ih++) {
            char *strh = str[i][ih];
            bool ch = ih ^ 1;
            int uh = getv(i, ch);
            int invuh = getv(i, !ch);
            int lenstrh = strlen(strh);
            // check if there is wall in word, or out of boarder
            for (int p = 0; p < lenstrh; p++) {
                if (begin_x[label[i]] + p >= W) {
                    add_edge(uh, invuh);
                }
                if (mp[begin_y[label[i]]][begin_x[label[i]] + p] == -1) {
                    add_edge(uh, invuh);
                }
            }
        }
    }
    for (int i = N; i < n; i++) {
        if (choice[i] == 1) {
            add_edge(n + i, i);
        }
        for (int iv = 0; iv < choice[i]; iv++) {
            char *strv = str[i][iv];
            bool cv = iv ^ 1;
            int uv = getv(i, cv);
            int invuv = getv(i, !cv);
            int lenstrv = strlen(strv);
            for (int q = 0; q < lenstrv; q++) {
                if (begin_y[label[i]] + q >= H) {
                    add_edge(uv, invuv);
                }
                if (mp[begin_y[label[i]] + q][begin_x[label[i]]] == -1) {
                    add_edge(uv, invuv);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = N; j < n; j++) {

            for (int ih = 0; ih < choice[i]; ih++) {
                char *strh = str[i][ih];
                int lenstrh = strlen(strh);
                bool ch = ih ^ 1;
                int uh = getv(i, ch);
                int invuh = getv(i, !ch);
                for (int iv = 0; iv < choice[j]; iv++) {
                    char *strv = str[j][iv];
                    int lenstrv = strlen(strv);
                    bool cv = iv ^ 1;
                    int uv = getv(j, cv);
                    int invuv = getv(j, !cv);

                    int crossy = begin_y[label[i]];
                    int crossx = begin_x[label[j]];

                    int p = crossx - begin_x[label[i]];
                    int q = crossy - begin_y[label[j]];

                    if (p < 0 || p >= lenstrh || q < 0 || q >= lenstrv) {
                        continue;
                    }
                    if (strh[p] != strv[q]) {
                        add_edge(uh, invuv);
                        add_edge(uv, invuh);
                    }
                }
            }
        }
    }
}

int dfn[maxn * 2], low[maxn * 2], dfncnt;
int scc[maxn * 2], sc;
int ins[maxn * 2], stk[maxn * 2], tp;
void tarjan(int u)
{
    low[u] = dfn[u] = ++dfncnt;
    stk[++tp] = u;
    ins[u] = true;
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
        while (stk[tp] != u) {
            scc[stk[tp]] = sc;
            ins[stk[tp]] = false;
            --tp;
        }
        scc[stk[tp]] = sc;
        ins[stk[tp]] = false;
        --tp;
    }
}

int res[maxn];
int ans_map[maxs][maxs];
void gen_map()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (mp[i][j] == -1) {
                ans_map[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < N; i++) { // horizon
        int lab = label[i];
        char *s = str[i][res[i]];
        int lens = strlen(s);
        for (int p = 0; p < lens; p++) {
            ans_map[begin_y[lab]][begin_x[lab] + p] = s[p];
        }
    }
    for (int i = N; i < n; i++) { // vertical
        int lab = label[i];
        char *s = str[i][res[i]];
        int lens = strlen(s);
        for (int q = 0; q < lens; q++) {
            ans_map[begin_y[lab] + q][begin_x[lab]] = s[q];
        }
    }
}

void print_map()
{
    /*
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1 || ans_map[i][j] == 0)
                cout << ans_map[i][j] << '\t';
            else
                cout << (char)ans_map[i][j] << '\t';
        }
        cout << endl;
    }
    */
    for (int i = 0; i < W * 4 + 1; i++) putchar('-');
    putchar('\n');
    for (int i = 0; i < H; i++) {
        putchar('|');
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) printf("***|");
            else printf("   |");
        }
        putchar('\n');
        putchar('|');
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) printf("***|");
            else if (ans_map[i][j] == 0) printf("   |");
            else {
                printf(" %c |", ans_map[i][j]);
            }
        }
        putchar('\n');
        putchar('|');
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) printf("***|");
            else printf("   |");
        }
        putchar('\n');
        for (int i = 0; i < W * 4 + 1; i++) putchar('-');
        putchar('\n');
    }
}

int main()
{
    scanf("%d%d%d%d", &H, &W, &N, &M);
    n = N + M;
    fgets(tmp, maxline, stdin);
    fgets(tmp, maxline, stdin);
    for (int i = 0; i < H; i++) {
        fgets(tmp, maxline, stdin);
        char c;
        int p = 1;
        for (int j = 0; j < W; j++) {
            char *cell = tmp + 1 + 4 * j;
            if (cell[0] == '*') mp[i][j] = -1;
            else if (cell[0] == ' ') mp[i][j] = 0;
            else {
                mp[i][j] = stod(cell);
                begin_y[mp[i][j]] = i;
                begin_x[mp[i][j]] = j;
            }
        }
        fgets(tmp, maxline, stdin);
        fgets(tmp, maxline, stdin);
        fgets(tmp, maxline, stdin);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", label + i, choice + i);
        for (int j = 0; j < choice[i]; j++) {
            scanf("%s", &str[i][j]);
        }
    }
    build_graph();
    /*
    for (int u = 0; u < n * 2; u++) {
        clog << u << ":";
        for (int v : G[u]) clog << " " << v;
        clog << endl;
    }
    */
    for (int i = 0; i < n * 2; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 0; i < n; i++) {
        if (scc[i] == scc[n + i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 0; i < n; i++) {
        if (scc[i] < scc[n + i]) {
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        clog << i << ": " << res[i] << endl;
    }
    */
    gen_map();
    print_map();
    return 0;
}