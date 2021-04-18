#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int maxw = 110;
const int maxh = 110;
const int maxc = 510;
const int maxnc = 30;
const int spc = 170;
const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int w, h;
char map[maxh][maxw];
bool vis[maxh][maxw];

struct pt {
    int y, x;
};
typedef pair<int, int> P;

pt tmp[spc];
int len;

struct clu {
    double dsum;
    char ch;
};

clu clus[maxnc];
int cnt = 0;

void bfs(int y, int x)
{
    // insert the cluster into tmp
    len = 0;
    vis[y][x] = true;
    tmp[len++] = (pt){y, x};
    queue<P> q;
    q.push(P(y, x));
    while (!q.empty()) {
        P p = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            P np = P(p.first + dy[i], p.second + dx[i]);
            if (np.first < 0 || np.first >= h || np.second < 0 || np.second >= w) continue;
            if (map[np.first][np.second] == '1' && !vis[np.first][np.second]) {
                vis[np.first][np.second] = true;
                tmp[len++] = (pt){np.first, np.second};
                q.push(np);
            }
        }
    }
    #ifdef debug
    static int bfst;
    printf("bfs(%d, %d)#%d: %d\n", y, x, bfst++, len);
    #endif
}

double _bash()
{
    double ans = 0.0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            ans += sqrt((tmp[i].x - tmp[j].x) * (tmp[i].x - tmp[j].x) + (tmp[i].y - tmp[j].y) * (tmp[i].y - tmp[j].y));
        }
    }
    return ans;
}

void color()
{
    double c_bash = _bash();
    char c = -1;
    for (int i = 0; i < cnt; i++) {
        if (fabs(clus[i].dsum - c_bash) < 0.00001) {
            c = clus[i].ch;
            break;
        }
    }
    if (c == -1) {
        c = 'a' + cnt;
        clus[cnt] = (clu){c_bash, c};
        cnt++;
    }
    for (int i = 0; i < len; i++) {
        map[tmp[i].y][tmp[i].x] = c;
    }
}

int main()
{
    scanf("%d%d", &w, &h);
    for (int i = 0; i < h; i++)
        scanf("%s", map[i]);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '1') {
                bfs(i, j);
                color();
            } else
                vis[i][j] = true;
        }
    for (int i = 0; i < h; i++)
        puts(map[i]);
    return 0;
}