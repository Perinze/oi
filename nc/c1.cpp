#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int xx1[1010];
int Hash0[250510];
int Hash1[501010];    // if xx1 + xx1 exists

int main()
{
    for (int i = -500; i <= 500; i++)
        xx1[i + 500] = i * (i + 1);
    for (int i = 0; i <= 1000; i++)
        Hash0[xx1[i]]++;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(Hash1, 0, sizeof(Hash1));
        for (int i = -n; i <= n; i++)
            for (int j = -n; j <= n; j++)
                Hash1[xx1[i + 500] + xx1[j + 500]] = Hash0[xx1[i + 500]] * Hash0[xx1[j + 500]];
        int lim = n * (n + 1) * 2;
        int ans = 0;
        for (int i = 0; i < lim / k; i++) {
            //if (i * k > 501000) break;
            if (Hash1[i] && Hash1[i * k])
                if (i * k == lim)
                    ans += Hash1[i] * 1;
                else
                    ans += Hash1[i] * Hash1[i * k];
        }
        if (k == 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}