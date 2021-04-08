#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> siz;
int nxt['z' + 1][200010];
bool flag['z' + 1];

int ans = 0;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    char lst = 'A';
    char c;
    int len = 0;
    for (int i = 0; i < n; i++) {
        c = getchar();
        flag[c] = true;
        if (c == lst) siz[len - 1]++;
        else {
            siz.push_back(1);
            map[c].push_back(i);
            len++;
        }
        lst = c;
    }
    for (int c = 'a'; c <= 'z'; c++) {
        if (!flag[c]) continue;
        nxt[c][n - 1] = 
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 'a'; c <= 'z'; c++) {
            if (!flag[c]) continue;

        }
    }
    /*
    for (int i = 0; i < siz.size(); i++)
        printf("%d ", siz[i]);
    putchar('\n');
    */
    for (int i = 'a'; i <= 'c'; i++)
    {
        for (int j = 0; j < map[i].size(); j++)
            printf("%d ", map[i][j]);
        putchar('\n');
    }
    char t[200010];
    scanf("%s", t);

    return 0;
}
