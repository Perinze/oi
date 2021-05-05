#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10010;
typedef pair<string, int> P;
int n, m;
vector<int> digit;
bool vis[maxn];

string bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<P> q;
    for (int i = 0; i < (int)digit.size(); i++) {
        if (digit[i] == 0) continue;
        string s;
        s.push_back(digit[i] + '0');
        int x = digit[i] % n;
        if (x == 0)
            return s;
        q.push(P(s, x));
        vis[x] = true;
    }
    while (!q.empty()) {
        P p = q.front(); q.pop();
        string s = p.first;
        int x = p.second;
        for (int i = 0; i < (int)digit.size(); i++) {
            int nx = (x * 10 + digit[i]) % n;
            if (vis[nx])
                continue;
            string ns = s;
            ns.push_back(digit[i] + '0');
            if (nx == 0)
                return ns;
            q.push(P(ns, nx));
            vis[nx] = true;
        }
    }
    return "-1";
}

bool mark[10];

int main()
{
    ios::sync_with_stdio(false);
    int kase = 1;
    while (cin >> n >> m) {
        memset(mark, 0, sizeof(mark));
        digit.clear();
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            mark[x] = true;
        }
        for (int i = 0; i <= 9; i++)
            if (!mark[i])
                digit.push_back(i);
        cout << "Case " << kase++ << ": " << bfs() << endl;
    }
    return 0;
}