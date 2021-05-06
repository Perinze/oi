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
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans + 9 + tmp[i] - '0';
        }
        cout << ans << endl;
    }
    return 0;
}