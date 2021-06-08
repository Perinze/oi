#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n;
//int a[maxn];
vector<int> a;
vector<int> b;
vector<int> method[2];
int which[maxn];
int res[2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    /*
    for (int i = 0; i < n; i++) {
        int bigger = (res[0] < res[1] ? 1 : 0);
        if (which[i] == bigger && res[bigger] - res[!bigger] >= a[i]) {
            which[i] = !which[i];
            res[bigger] -= a[i];
            res[!bigger] += a[i];
        }
    }
    */
    while (a.size() > 2) {
        sort(a.begin(), a.end());
        bool update = false;
        for (int i = 0; i + 2 < a.size(); i++) {
            if (a[i] + a[i + 1] <= a[i + 2]) {
                a[i] += a[i + 1];
                a.erase(a.begin() + i + 1);
                update = true;
                break;
            }
        }
        if (!update) break;
    }
    for (int i = 0; i < a.size(); i++) {
        int idx = (res[0] < res[1] ? 0 : 1);
        res[idx] += a[i];
    }
    cout << max(res[0], res[1]) << endl;
    return 0;
}