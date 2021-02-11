#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int k = i ^ j;
            if (j <= k && k <= n && i + j > k) ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}