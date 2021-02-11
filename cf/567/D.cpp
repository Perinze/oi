#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, a, m;
int x[200001];

bool C(int y)
{
    vector<int> shot;
    for (int i = 0; i < y; i++)
        shot.push_back(x[i]);
    sort(shot.begin(), shot.end());
    /*
    printf("in C\n");
    for (int i = 0; i < y; i++)
        printf("%d ", shot[i]);
    putchar('\n');
    */
    int res = 0;
    int l = 1;
    int r;
    for (int i = 0; i < y; i++) {
        r = shot[i] - 1;
        res += (r - l + 2) / (a + 1);
        l = shot[i] + 1;
    }
    res += (n - l + 2) / (a + 1);
    return res < k;
}

int main()
{
    scanf("%d%d%d%d", &n, &k, &a, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", x + i);
    /*
    for (int i = 1; i <= m; i++)
        printf("%d ", C(i));
    */
    int l = 1;
    int r = m;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (C(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}