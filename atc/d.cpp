#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int arr[a + b];
    for (int i = 0; i < a; i++) arr[i] = 0;
    for (int i = a; i < a + b; i++) arr[i] = 1;
    for (int i = 1; i < k; i++)
        next_permutation(arr, arr + a + b);
    for (int i = 0; i < a + b; i++)
        putchar(arr[i] == 0 ? 'a' : 'b');
    putchar('\n');
    return 0;
}