#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
typedef pair<int, int> P;
//P a[200010];
int a[200010];
vector<int> rev[2500010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        rev[x].push_back(i);
        //a[i] = P(x, i);
        if (rev[x].size() >= 4) {
            // found
            puts("YES");
            printf("%d %d %d %d\n", rev[x][0], rev[x][1], rev[x][2], i);
            return 0;
        }
    }

    sort(:w
    )
    for (int i = 1; i <= n; i++) {
        int x = a[i].first;
        for (int j = i + 1; j <= n; j++) {
            int y = a[j].first;

            int tmp = x + y;
            if (tmp % 2 == 0) {
                int hlf = tmp / 2;
                if (rev[hlf].size() >= 2) {
                    puts("YES");
                    printf("%d %d %d %d", i, j, rev[hlf][0], rev[hlf][1]);
                    return 0;
                }
            }

            tmp = x - y;
            if (ite != s.eop()) {
                P res = ite->second;
                int k = res.first;
                int l = res.second;
                if (i == k || i == l || j == k || j == l) goto notfound;

                // found
                puts("YES");
                printf("%d %d %d %d\n", i, l, k, j);
                return 0;
            }
            s[tmp] = P(i, j);
        }
    }
    puts("NO");

    return 0;
}