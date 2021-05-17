#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int kase = 1;
    while (T--) {
        int bat;
        cin >> bat;
        cout << "Case #" << kase++ << ":" << endl;
        bat /= 10;
        cout << "*------------*" << endl;
        for (int i = 10; i > bat; i--)
            cout << "|............|" << endl;
        for (int i = bat; i > 0; i--)
            cout << "|------------|" << endl;
        cout << "*------------*" << endl;
    }
    return 0;
}