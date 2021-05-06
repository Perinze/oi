#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool done[26];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        memset(done, 0, sizeof(done));
        int n;
        string str;
        cin >> n >> str;
        char tmp = -1;
        for (int i = 0; i < n; i++) {
            char crt = str[i] - 'A';
            if (crt != tmp && done[crt]) {
                cout << "NO" << endl;
                break;
            }
            if (i == n - 1) {
                cout << "YES" << endl;
            }
            tmp = crt;
            done[crt] = true;
        }
    }
    return 0;
}