#include <cstdio>

typedef long long ll;
char tmp[5];

int main()
{
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        scanf("%s", tmp);
        if (tmp[0] == 'N') continue;
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        if (x + y != z) {
            fprintf(stderr, "x + y != z at %lld %lld\n", a, b);
            fprintf(stderr, "where x, y, z = %lld %lld %lld\n", x, y, z);
            return 1;
        }
        if (x % a || y % a || z % a) {
            fprintf(stderr, "not divisible by A at %lld %lld\n", a, b);
            fprintf(stderr, "where x, y, z = %lld %lld %lld\n", x, y, z);
            return 1;
        }
        int ngd = 0;
        if (x % (a * b) == 0) ngd++;
        if (y % (a * b) == 0) ngd++;
        if (z % (a * b) == 0) ngd++;
        if (ngd == 0) {
            fprintf(stderr, "good number not exists at %lld %lld\n", a, b);
            fprintf(stderr, "where x, y, z = %lld %lld %lld\n", x, y, z);
            return 1;
        }
        if (ngd > 1) {
            fprintf(stderr, "more than one good number at %lld %lld\n", a, b);
            fprintf(stderr, "where x, y, z = %lld %lld %lld\n", x, y, z);
            return 1;
        }
    }
    return 0;
}