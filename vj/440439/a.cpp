#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int dat[4 * maxn];
int M, P;
int n;

void init(int m)
{
    n = 1;
    while (n < m) n *= 2;
}

void update(int k, int a)
{
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
}

int main()
{
    cin >> M >> P;
    init(M);
    int cnt = 0;
    int res = 0;
    char tmp[2];
    int arg;
    for (int i = 0; i < M; i++) {
        cin >> tmp >> arg;
        if (tmp[0] == 'A') {
            update(cnt++, (arg + res) % P);
            //printf("add %d\n", (arg + res) % P);
        } else {
            printf("%d\n", res = query(cnt - arg, cnt, 0, 0, n));
        }
    }
    return 0;
}