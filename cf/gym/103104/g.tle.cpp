#include <bits/stdc++.h>
using namespace std;

const int maxs = 510;
const int maxn = 1010;

int H, W, N, M;
int n;
vector<int> G[maxn * 2];
int mp[maxs][maxs]; // -1 wall, 0 blank, >= 1 begin marks
int begin_x[maxn], begin_y[maxn]; // 0-ordered
int label[maxn];
int choice[maxn];
string str[maxn][2];
int dir[maxn]; // 0 - horizon, 1 - vertical

void add_edge(int u, int v)
{
    G[u].push_back(v);
    //clog << u << " -> " << v << endl;
}

inline int getv(int u, bool c)
{
    return c ? u : u + n;
}

void build_graph()
{
    for (int i = 0; i < N; i++) {
        for (int j = N; j < n; j++) {

            for (int ih = 0; ih < choice[i]; ih++) {
                string strh = str[i][ih];
                bool ch = ih ^ 1;
                int uh = getv(i, ch);
                int invuh = getv(i, !ch);
                for (int iv = 0; iv < choice[j]; iv++) {
                    string strv = str[j][iv];
                    bool cv = iv ^ 1;
                    int uv = getv(j, cv);
                    int invuv = getv(j, !cv);

                    //clog << "horizon #" << i << ", vertical #" << j << endl;
                    //clog << "strh: " << strh << ", strv: " << strv << endl;

                    bool cont = true;
                    for (int p = 0; cont && p < strh.size(); p++) {
                        //clog << "strh[" << p << "]: " << strh[p] << ' ';
                        for (int q = 0; cont && q < strv.size(); q++) {
                            //clog << "strv[" << q << "]: " << strv[q] << endl;
                            if (begin_x[label[i]] + p >= W) {
                                add_edge(uh, invuh);
                                cont = false; break;
                            }
                            if (begin_y[label[j]] + q >= H) {
                                add_edge(uv, invuv);
                                cont = false; break;
                            }
                            if (mp[begin_y[label[i]]][begin_x[label[i]] + p] == -1) {
                                //clog << "strh in wall: " << begin_y[label[i]] << ", " << begin_x[label[i]] + p << endl;
                                add_edge(uh, invuh);
                                cont = false; break;
                            }
                            if (mp[begin_y[label[j]] + q][begin_x[label[j]]] == -1) {
                                //clog << "strv in wall: " << begin_y[label[j]] + q << ", " << begin_x[label[j]] << endl;
                                add_edge(uv, invuv);
                                cont = false; break;
                            }
                            if (begin_x[label[i]] + p == begin_x[label[j]] && begin_y[label[i]] == begin_y[label[j]] + q) {
                                //clog << "both at " << begin_y[label[i]] << ", " << begin_x[label[j]] << endl;
                                if (strh[p] != strv[q]) {
                                    //clog << "not same letter" << endl;
                                    add_edge(uh, invuv);
                                    add_edge(uv, invuh);
                                }
                            }
                        }
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
        string &s = str[i][res[i]];
        for (int p = 0; p < s.size(); p++) {
            ans_map[begin_y[lab]][begin_x[lab] + p] = s[p];
        }
    }
    for (int i = N; i < n; i++) { // vertical
        int lab = label[i];
        string &s = str[i][res[i]];
        for (int q = 0; q < s.size(); q++) {
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
    for (int i = 0; i < W * 4 + 1; i++) cout << '-';
    cout << endl;
    for (int i = 0; i < H; i++) {
        cout << '|';
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) cout << "***|";
            else cout << "   |";
        }
        cout << endl;
        cout << '|';
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) cout << "***|";
            else if (ans_map[i][j] == 0) cout << "   |";
            else {
                cout << ' ' << (char)ans_map[i][j] << " |";
            }
        }
        cout << endl;
        cout << '|';
        for (int j = 0; j < W; j++) {
            if (ans_map[i][j] == -1) cout << "***|";
            else cout << "   |";
        }
        cout << endl;
        for (int i = 0; i < W * 4 + 1; i++) cout << '-';
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> H >> W >> N >> M;
    n = N + M;
    string tmp;
    getline(cin, tmp);
    getline(cin, tmp);
    for (int i = 0; i < H; i++) {
        getline(cin, tmp);
        char c;
        int p = 1;
        for (int j = 0; j < W; j++) {
            string cell = tmp.substr(1 + 4 * j, 3);
            if (cell[0] == '*') mp[i][j] = -1;
            else if (cell[0] == ' ') mp[i][j] = 0;
            else {
                mp[i][j] = stod(cell);
                begin_y[mp[i][j]] = i;
                begin_x[mp[i][j]] = j;
            }
        }
        getline(cin, tmp);
        getline(cin, tmp);
        getline(cin, tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> label[i] >> choice[i];
        for (int j = 0; j < choice[i]; j++) {
            cin >> str[i][j];
        }
        if (i < n) dir[i] = 0;
        else dir[i] = 1;
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
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        if (scc[i] < scc[n + i]) {
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }
    gen_map();
    print_map();
    return 0;
}