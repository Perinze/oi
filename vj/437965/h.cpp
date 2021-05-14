#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1010;
int n;
int bit[maxn][maxn];

int query(int i_, int j_)
{
    int s = 0;
    for (int i = i_; i > 0; i -= i & -i) {
        for (int j = j_; j > 0; j -= j & -j) {
            s += bit[i][j];
        }
    }
    return s;
}

void add(int i_, int j_, int x)
{
    for (int i = i_; i <= n; i += i & -i) {
        for (int j = j_; j <= n; j += j & -j) {
            bit[i][j] += x;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        memset(bit, 0, sizeof(bit));
        static int q;
        cin >> n >> q;
        while (q--) {
            char cmd[2];
            cin >> cmd;
            int a, b, c, d;
            if (cmd[0] == 'C') {
                cin >> a >> b >> c >> d;
                add(a, b, 1);
                add(c + 1, b, 1);
                add(a, d + 1, 1);
                add(c + 1, d + 1, 1);
            } else if (cmd[0] == 'Q') {
                cin >> a >> b;
                int res = query(a, b);
                cout << res % 2 << endl;
            } else {
                cout << "error" << endl;
                return 1;
            }
        }
        if (T > 1) cout << endl;
    }
    return 0;
}