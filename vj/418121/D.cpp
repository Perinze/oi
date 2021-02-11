#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int ds[8][8];
int num[8];

char gch()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') return c;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ds[i][j] = gch() - '0';
        }
    }
    int perm[k];
    for (int i = 0; i < k; i++) perm[i] = i;
    int ans = 0x3f3f3f3f;
    do
    {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                num[i] = num[i] * 10 + ds[i][perm[j]];
            }
        }
        sort(num, num + n);
        ans = min(ans, num[n - 1] - num[0]);
    } while (next_permutation(perm, perm + k));
    printf("%d\n", ans);
    return 0;
}