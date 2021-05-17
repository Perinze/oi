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
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            Hash1[xx1[i] + xx1[j]] = Hash0[xx1[i]] * Hash0[xx1[j]];
    //for (int i = 0; i <= 4; i++) printf("%d ", Hash1[i]);
    //puts("");
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int lim = n * (n + 1) * 2;
        int ans = 0;
        for (int i = 0; i <= lim / k; i++) {
            //if (i * k > 501000) break;
            if (Hash1[i] && Hash1[i * k]) {
                if (i * k == lim)
                    ans += Hash1[i] * 1;
                else
                    ans += Hash1[i] * Hash1[i * k];
            }
        }
        if (k == 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}