#include <cstdio>

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

void test1(int x)
{
    unsigned long t1, t2;
    t1 = (unsigned long)GetCycleCount();
    for (int i = x; i > 0; i -= i & (-i));
    t2 = (unsigned long)GetCycleCount();
    printf("test1: %f\n", (t2 - t1) * 1.0 / FREQUENCY);
}

inline int lowbit(int x)
{
    return x & (-x);
}

void test2(int x)
{
    unsigned long t1, t2;
    t1 = (unsigned long)GetCycleCount();
    for (int i = x; i > 0; i -= lowbit(i));
    t2 = (unsigned long)GetCycleCount();
    printf("test2: %f\n", (t2 - t1) * 1.0 / FREQUENCY);
}

int main(void)
{
    test1(114514);
    test2(114514);
    return 0;
}