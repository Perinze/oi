#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, bool> P;
P w[10];

int input(int &x)
{
    char c;
    while ((c = getchar()) < 'a' || c > 'j');
    x = c - 'a';
    int k = 1;
    while ((c = getchar()) >= 'a' && c <= 'j')
    {
        x = x * 10 + c - 'a';
        k++;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, k = input(x);
        int c;
        for (int j = 0, c = 1; j < k; j++, c *= 10)
        {
            int d = x % 10;
            w[d].first += c;
            if (j == k - 1) w[d].second = true;
            x /= 10;
        }
    }
    int ans = 0;
    sort(w, w + 10);
    reverse(w, w + 10);
    #ifdef DEBUG
    for (int i = 0; i < 10; i++)
    {
        printf("%c %d %d\n", i + 'a', w[i].first, w[i].second);
    }
    #endif
    for (int i = 0; i < 10; i++)
    {
        if (w[i].first > 0 && w[i].second == false)
        {
            w[i].first = -1;
            break;
        }
    }
    int digit = 1;
    for (int i = 0; i < 10; i++)
    {
        if (w[i].first > 0)
        {
            ans += w[i].first * digit++;
        }
    }
    printf("%d\n", ans);
    return 0;
}