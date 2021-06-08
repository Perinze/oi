#include <cstdio>
#include <algorithm>
using namespace std;

int a[20][20];
int line[5];

bool win()
{
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 5; i++)
        {
                if (line[i] == 1) cnt1++;
                else if (line[i] == 2) cnt2++;
        }
        if (cnt1 && cnt2) return false;
        int cnt = max(cnt1, cnt2);
        if (cnt == 4) return true;
        else return false;
}

void solve()
{
        for (int i = 0; i < 12; i++)
                for (int j = 0; j < 12; j++)
                        scanf("%d", &a[i][j]);

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j <= 7; j++) {
                for (int k = 0; k < 5; k++)
                    line[k] = a[i][j + k];
            }
            if (win()) {
                printf("YES");
                return;
            }
        }

        for (int j = 0; j < 12; j++) {
                for (int i = 0; i <= 7; i++) {
                        for (int k = 0; k < 5; k++)
                                line[k] = a[i + k][j];
                        }
                        if (win()) {
                                printf("YES");
                                return;
                        }
        }

        for (int i = 0; i <= 7; i++) {
                for (int j = 0; j <= 7; j++) {
                        for (int k = 0; k < 5; k++) {
                                line[k] = a[i + k][j + k];
                        }
                        if (win()) {
                                printf("YES");
                                return;
                        }

                        for (int k = 0; k < 5; k++) {
                                line[k] = a[i + 4 - k][j + k];
                        }
                        if (win()) {
                                printf("YES");
                                return;
                        }
                }
        }
        printf("NO");
}
int main()
{
        //freopen("1.txt", "r", stdin);
        solve();
        return 0;
}