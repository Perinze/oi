#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int n, t, k;
int sum[maxn];

int main()
{
    scanf("%d%d", &n, &t);
    scanf("%d", &k);
    int l = 1, r = n;
    int q = 20;
    while (l < r) {
        if (!q) {
            printf("! %d\n", l);
            exit(0);
        }
        int mid = (l + r) / 2;
        printf("? %d %d\n", 1, mid);
        q--;
        scanf("%d", sum + mid);
        if (mid - sum[mid] == k) {
            if (sum[mid - 1] == -1) {
                r = mid;
                continue;
            }
            if (mid - 1 - sum[mid - 1] < k) {
                printf("! %d\n", mid);
                fflush(stdout);
                exit(0);
            }
        } else if (mid - sum[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("! %d\n", l);
    return 0;
}