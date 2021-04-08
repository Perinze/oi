#include <cstdio>
#include <cctype>

namespace io {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)    \
        ? EOF                                                                   \
        : *p1++)
    
    template <typename T>
    inline T read()
    {
        T x = 0, s= 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') s = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        return x * s;
    }
    inline char gch()
    {
        return gc();
    }
}

int main(void)
{
    int T = io::read<int>();
    for (int cas = 1; cas <= T; cas++) {
        int dec[4];
        for (int i = 0; i < 4; i++)
            dec[i] = io::read<int>();
        int bin;
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            bin = 0;
            char c = io::gch();
            while (!isdigit(c)) c = io::gch();
            while (isdigit(c))
                bin = (bin << 1) | (c ^ 48), c = io::gch();
            if (dec[i] != bin) flag = false;
        }
        printf("Case %d: %s\n", cas, flag ? "Yes" : "No");
    }
    return 0;
}