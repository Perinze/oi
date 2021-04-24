#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 10;
int bit[maxn];
bool prime[maxn];

void add(int i, int x)
{
    for (; i <= maxn; i += i & -i)
        bit[i] += x;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxn; i++)
        if (prime[i])
            for (int j = i * 2; j < maxn; j += i)
                prime[j] = false;
}

int main()
{
    sieve();
    for (int i = 5; i < maxn; i++)
        if (prime[i - 2] && prime[i])
            add(i, 1);
    int n;
    while (~scanf("%d", &n)) {
        if (n < 0) break;
        printf("%d\n", query(n));
    }
    return 0;
}