#include <bits/stdc++.h>
using namespace std;

// a[2*i]: use a certain car in a certain race
// a[2*i-1]: dont use a certain car in a certain race
// i in [1,3n]
// [1,n]: use a in i
// [n+1,2n]: use b in i
// [2n+1,3n]: use c in i

// i, n+i, 2n+i cannot be 1 the same time
// if i is map a, a[i]->a[n+i],a[2n+i]
// if i is map b, a[n+i]->a[i],a[2n+i]
// if i is map c, a[2n+i]->a[i],a[n+i]
// if i is map x,

// (i, hi, j, hj)
// a[i+f(hi)]<->a[j+f(hj)]

const int maxn = 5e4 + 10;

vector<int> G[maxn * 3];
bool vis[maxn];
int cnt;
bool found = false;
int n, d;
string S;
char res[maxn];

void dfs(int v)
{
    if (found) return;
    if (vis[v]) return;
    vis[v] = true;
    res[((v - 1) % (n * 2)) / 2] = (v - 1) / 2 / n + 'A';
    cnt++;
    if (cnt == n) {
        cout << res << endl;
        found = true;
        res[((v - 1) % (n * 2)) / 2] = 0;
        return;
    }
    for (auto u : G[v]) {
        if (vis[((u - 1) % (n * 2)) / 2]) {
            vis[v] = false;
            cnt--;
            return;
        }
        dfs(((u - 1) % (n * 2)) / 2);
        if (found) return;
    }
    if (G[v].empty()) {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                if (found) return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> d >> S;
    for (int i = 0; i < S.size(); i++)
    {
        G[i * 2 + 1].push_back((n + i) * 2), G[i * 2 + 1].push_back((n * 2 + i) * 2);
        G[(n + i) * 2 + 1].push_back(i * 2), G[(n + i) * 2 + 1].push_back((n * 2 + i) * 2);
        G[(n * 2 + i) * 2 + 1].push_back(i * 2), G[(n * 2 + i) * 2 + 1].push_back((n + i) * 2);

        char c = S[i];
        if (c == 'x')
            continue;
        if (c == 'a')
            G[i * 2 + 1].push_back((n + i) * 2 + 1), G[i * 2 + 1].push_back((n * 2 + i) * 2 + 1);
        else if (c == 'b')
            G[(n + i) * 2 + 1].push_back(i * 2 + 1), G[(n + i) * 2 + 1].push_back((n * 2 + i) * 2 + 1);
        else if (c == 'c')
            G[(n * 2 + i) * 2 + 1].push_back(i * 2 + 1), G[(n * 2 + i) * 2 + 1].push_back((n + i) * 2 + 1);
    }
    int tmp;
    cin >> tmp;
    while (tmp--) {
        int i, j;
        char ci, cj;
        cin >> i >> ci >> j >> cj;
        G[(n * (ci - 'A') + i) * 2 + 1].push_back((n * (cj - 'A') + j) * 2 + 1);
    }
    dfs(0);
    if (!found) dfs(n + 1);
    if (!found) dfs(n * 2 + 1);
    if (!found) cout << -1 << endl;

    return 0;
}