#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        string tmp;
        cin >> tmp;
        int n = (int)tmp.size();
        int h = tmp[0] - '0';
        int ans = 9 * (n - 1) + h; 
        for (int i = 1; i < n; i++)
            if (tmp[i] - '0' > h)
                break;
            else if (tmp[i] - '0' < h) {
                ans -= 1;
                break;
            }
        cout << ans << endl;
    }
    return 0;
}