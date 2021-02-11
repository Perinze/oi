#include <stdio.h>

char seq[100];
int len;

int main()
{
    len = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == 'Q' || c == 'A')
            seq[len++] = c;
    }
    int ans = 0;
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            for (int k = j + 1; k < len; k++)
                if (seq[i] == 'Q' && seq[j] == 'A' && seq[k] == 'Q') ans++;
    printf("%i\n", ans);
    return 0;
}