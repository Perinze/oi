#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int p[100010];
int np[100010];
int ptr;
int nptr;
int n;
int segmax[100010];
int segptr[100010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(segmax, -1, sizeof(segmax));
        scanf("%d", &n);
        for (int i = n - 1; i >= 0; i--) scanf("%d", p + i);
        segmax[n - 1] = p[n - 1];
        segptr[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (p[i] > segmax[i + 1]) {
                segmax[i] = p[i];
                segptr[i] = i;
            } else {
                segmax[i] = segmax[i + 1];
                segptr[i] = segptr[i + 1];
            }
        }
        //for (int i = 0; i < n; i++) printf("%d ", segptr[i]);
        //putchar('\n');
        ptr = 0;
        nptr = 0;
        while (ptr < n) {
            nptr = segptr[ptr];
            int len = nptr - ptr;
            //printf("ptr: %d, nptr: %d, len: %d\n", ptr, nptr, len);
            for (int i = 0; i <= len; i++) {
                np[ptr + i] = p[ptr + len - i];
            }
            ptr = nptr + 1;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", np[i]);
        }
        putchar('\n');
    }
    return 0;
}