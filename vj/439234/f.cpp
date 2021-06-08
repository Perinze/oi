#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5010;
int x1, y1, x2, y2;
int xu[maxn], xl[maxn];
int n, m;
int ans[maxn];

inline int cross(int a, int b, int c, int d)
{
    // negative - right, positive - left
    return a * d - b * c;
}

int test(int x, int y, int i)
{
    int c1 = cross(xu[i] - xl[i], y1 - y2, x - xl[i], y - y2);
    int c2 = cross(xu[i + 1] - xl[i + 1], y1 - y2, x - xl[i + 1], y - y2);
    if (c1 > 0 && c2 > 0) // both left
        return -1;
    else if (c1 < 0 && c2 < 0) // both right
        return 1;
    else
        return 0;
}

int binary_search(int x, int y)
{
    int l = 0, r = n;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        int t = test(x, y, mid);
        if (t == 0) {
            return mid;
        } else if (t == -1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return mid;
}

int main()
{
    bool kase1 = true;
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        if (kase1) kase1 = false;
        else puts("");
        xu[0] = xl[0] = x1;
        xu[n + 1] = xl[n + 1] = x2;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", xu + i, xl + i);
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            ans[binary_search(x, y)]++;
        }
        for (int i = 0; i <= n; i++) {
            printf("%d: %d\n", i, ans[i]);
        }
    }
    return 0;
}