#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> alpha[26];

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) alpha[i].push_back(-1);
    for (int i = 0; i < s.size(); i++) alpha[s[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++) alpha[i].push_back(s.size());
    int ans = 1000000;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i].size() <= 2) continue;
        int res = 0;
        for (int j = 0; j < alpha[i].size() - 1; j++)
        {
            res = max(res, alpha[i][j + 1] - alpha[i][j]);
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}