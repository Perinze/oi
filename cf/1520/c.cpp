#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 101;
int mat[maxn][maxn];
int n;

/*
inline bool adj(int x, int y)
{
    return x == y + 1 || y == x + 1;
}

inline bool matadj(int i, int j)
{
    int x = mat[i][j];
    if (i > 0 && adj(x, mat[i - 1][j])) return true;
    if (i < n - 1 && adj(x, mat[i + 1][j])) return true;
    if (j > 0 && adj(x, mat[j - 1][j])) return true;
    if (j < n - 1 && adj(x, mat[j + 1][j])) return true;
    return false;
}
*/

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt = 1;
        //bool fail = false;
        if (n == 2) {
            puts("-1");
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i % 2; j < n; j += 2) {
                mat[i][j] = cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = !(i % 2); j < n; j += 2) {
                mat[i][j] = cnt++;
                /*
                if (matadj(i, j)) {
                    fail = true;
                    break;
                }
                */
            }
            //if (fail) break;
        }
        /*
        if (fail) {
            puts("-1");
            continue;
        } else {
        */
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    printf("%d ", mat[i][j]);
                puts("");
            }
        //}
    }
    return 0;
}