#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int cream[200010];
int bot[200010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", cream + i);
            bot[i] = i - cream[i] + 1;
        }
        for (int i = n - 1; i > 0; i--)
            bot[i] = min(bot[i], bot[i + 1]);
        for (int i = 1; i <= n; i++) {
            if (i >= bot[i]) printf("%d ", 1);
            else printf("%d ", 0);
        }
        puts("");
    }
    return 0;
}