#include <cstdio>
#include <cstring>

const int MAXN = 200010;
int a[MAXN];
int bit[MAXN];
int n, m;

#ifdef DEBUG
#if defined (__i386__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned long long int x;
    __asm__ volatile("rdtsc": "=A"(x));
    return x;
}
#elif defined (__x86_64__)
static __inline__ unsigned long long GetCycleCount(void)
{
    unsigned hi, lo;
    __asm__ volatile("rdtsc": "=a"(lo), "=d"(hi));
    return ((unsigned long long) lo) | (((unsigned long long) hi) << 32);
}
#endif

#define FREQUENCY 3593.0000
#endif 

//#define LOWBIT

#ifdef LOWBIT
inline int lowbit(int x)
{
    return x & (-x);
}
#endif

void update(int i, int x)
{
    a[i] = x;
#ifdef LOWBIT
    for (; i <= n; i += lowbit(i)) {
#else
    for (; i <= n; i += i & -i) {
#endif
        bit[i] = x;
#ifdef LOWBIT
        for (int j = 1; j < lowbit(i); j <<= 1)
#else
        for (int j = 1; j < i & -i; j <<= 1)
#endif
            bit[i] = bit[i] > bit[i - j] ? bit[i] : bit[i - j];
    }
}

void init_read()
{
    int x;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[i] = x;
        bit[i] = x;
#ifdef LOWBIT
        for (int j = 1; j < lowbit(i); j <<= 1)
#else
        for (int j = 1; j < i & -i; j <<= 1)
#endif
            bit[i] = bit[i] > bit[i - j] ? bit[i] : bit[i - j];
    }
}

void query(int l, int r)
{
    int ans = 0;
    for (;;) {
        ans = ans > a[r] ? ans : a[r];
        if (l == r) break;
#ifdef LOWBIT
        for (r -= 1; r - l >= lowbit(r); r -= lowbit(r))
#else
        for (r -= 1; r - l >= r & -r; r -= r & -r)
#endif
            ans = ans > bit[r] ? ans : bit[r];
    }
    printf("%d\n", ans);
}

void solve()
{
    char cmd[2];
    int a, b;
    while (m--) {
        scanf("%s%d%d", cmd, &a, &b);
        if (cmd[0] == 'Q')
            query(a, b);
        else
            update(a, b);
    }
}

int main()
{
#ifdef DEBUG
    unsigned long t1, t2;
    t1 = (unsigned long)GetCycleCount();
#endif

    while (~scanf("%d%d", &n, &m)) {
        init_read();
        solve();
    }

#ifdef DEBUG
    t2 = (unsigned long)GetCycleCount();
    printf("test1: %f\n", (t2 - t1) * 1.0 / FREQUENCY);
#endif

    return 0;
}