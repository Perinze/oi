#include <cstdio>
#include <cstring>

typedef long long ll;

int n, k;
int a[100];
int b[100];
int s[100]; // 0< 1<= 2= 3>= 4>
ll dp[70][70];

int sign(char *s)
{
    if (strlen(s) == 1) {
        switch (s[0]) {
        case '<':
            return 0;
        case '=':
            return 2;
        case '>':
            return 4;
        }
    } else {
        switch (s[0]) {
        case '<':
            return 1;
        case '>':
            return 3;
        }
    }
    return -1;
}

bool C(int x, int y, int l, int r)
{
    for (int i = 0; i < k; i++) {
        if ((a[i] == x && b[i] == y) || (a[i] == y && b[i] == x))
            if (s[i] == 0 || s[i] == 4)
                return false;
        if ((a[i] == x || a[i] == y) && (b[i] >= l && b[i] <= r))
            if (s[i] >= 2)
                return false;
        if ((a[i] >= l && a[i] <= r) && (b[i] == x || b[i] == y))
            if (s[i] <= 2)
                return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    n *= 2;
    char tmp[3];
    for (int i = 0; i < k; i++) {
        scanf("%d %s %d", a + i, tmp, b + i);
        a[i]--; b[i]--;
        s[i] = sign(tmp);
    }
    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 0;
            if (len == 2) {
                if (C(i, j, j, i))
                    dp[i][j] = 1;
            } else {
                if (C(i, j, i + 1, j - 1))
                    dp[i][j] += dp[i + 1][j - 1];
                if (C(i, i + 1, i + 2, j))
                    dp[i][j] += dp[i + 2][j];
                if (C(j - 1, j, i, j - 2))
                    dp[i][j] += dp[i][j - 2];
            }
            //printf("[%d, %d]: %lld\n", i, j, dp[i][j]);
        }
    }
    printf("%lld\n", dp[0][n - 1]);
    return 0;
}