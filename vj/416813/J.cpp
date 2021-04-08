#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const ll factor[] = {2, 3, 5, 7};
vector<ll> humble;

void init()
{
    priority_queue<ll, vector<ll>, greater<ll> > q;
    q.push(1);

    ll last = -1;
    while (humble.size() < 5842)
    {
        ll x = q.top();
        q.pop();
        if (x == last) continue;
        humble.push_back(x);
        for (int i = 0; i < 4; i++)
        {
            q.push(x * factor[i]);
        }
        last = x;
    }
    sort(humble.begin(), humble.end());
}

string order(int x)
{
    if (x % 10 == 1 && x % 100 != 11) return "st";
    if (x % 10 == 2 && x % 100 != 12) return "nd";
    if (x % 10 == 3 && x % 100 != 13) return "rd";
    return "th";
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    int i;
    while (cin >> i)
    {
        i--;
        if (i == -1) break;
        cout << "The " << (i + 1) << order(i + 1) << " humble number is " << humble[i] << "." << endl;
    }
    return 0;
}