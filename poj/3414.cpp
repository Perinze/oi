#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int> P;
const int maxn = 110;

P pre[maxn][maxn];
int act[maxn][maxn];
bool vis[maxn][maxn];
int A, B, C;

P operate(int c, const P crt)
{
    switch (c) {
        case 0: // FILL 1
        return P(A, crt.second);
        case 1: // FILL 2
        return P(crt.first, B);
        case 2: // DROP 1
        return P(0, crt.second);
        case 3: // DROP 2
        return P(crt.first, 0);
        case 4: // POUR 1 2
        if (crt.first <= B - crt.second)
            return P(0, crt.first + crt.second);
        else
            return P(crt.first + crt.second - B, B);
        case 5: // POUR 2 1
        if (crt.second <= A - crt.first)
            return P(crt.first + crt.second, 0);
        else
            return P(A, crt.first + crt.second - A);
    }
    return P(-1, -1);
}

stack<int> bfs()
{
    queue<P> q;
    q.push(P(0, 0));
    vis[0][0] = true;
    P end;
    while (!q.empty()) {
        P p = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            P np = operate(i, p);
            if (vis[np.first][np.second]) continue;
            //cout << np.first << ' ' << np.second << endl;
            vis[np.first][np.second] = true;
            pre[np.first][np.second] = p;
            //cout << "from " << p.first << ' ' << p.second << endl;
            act[np.first][np.second] = i;
            //cout << "operation #" << i << endl;
            if (np.first == C || np.second == C) {
                end = np;
                //cout << "end is " << np.first << ' ' << np.second << endl;
                goto end;
            }
            //cout << endl;
            q.push(np);
        }
    }
    end:
    stack<int> s;
    while (end != P(0, 0)) {
        s.push(act[end.first][end.second]);
        end = pre[end.first][end.second];
    }
    return s;
}

int main()
{
    cin >> A >> B >> C;
    stack<int> res = bfs();
    if (res.empty()) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << res.size() << endl;
    while (!res.empty()) {
        int crt = res.top(); res.pop();
        switch (crt) {
            case 0:
            cout << "FILL(1)" << endl;
            break;
            case 1:
            cout << "FILL(2)" << endl;
            break;
            case 2:
            cout << "DROP(1)" << endl;
            break;
            case 3:
            cout << "DROP(2)" << endl;
            break;
            case 4:
            cout << "POUR(1,2)" << endl;
            break;
            case 5:
            cout << "POUR(2,1)" << endl;
            break;
        }
    }
    return 0;
}