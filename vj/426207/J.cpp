#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int tot = 1000000;

int n;
int a[tot + 5];
bool vis[tot + 5];
bool used[tot + 5];
vector<int> ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        vis[x] = true;
    }
    // x - 1 = s - y => y = s + 1 - x
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (used[x]) continue;
        int y = tot + 1 - x;
        if (vis[y]) {
            while (vis[tmp] || vis[tot + 1 - tmp]) tmp++;
            ans.push_back(tmp);
            ans.push_back(tot + 1 - tmp);
            vis[tmp] = vis[tot + 1 - tmp] = true;
            used[y] = true;
        } else {
            ans.push_back(y);
            vis[y] = true;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    putchar('\n');
    return 0;
}
