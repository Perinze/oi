#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int MAXV = 40;
map<string, int> rbt;
double d[MAXV][MAXV];
int V, E;

void floyd()
{
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
}

int main()
{
    string s1, s2;
    for (int cas = 1; ; cas++)
    {
        cin >> V;
        if (V == 0) break;

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (i == j) d[i][i] = 1;
                else d[i][j] = 0;

        for (int i = 0; i < V; i++)
        {
            cin >> s1;
            rbt[s1] = i;
        }

        cin >> E;
        double r;
        for (int i = 0; i < E; i++)
        {
            cin >> s1 >> r >> s2;
            d[rbt[s1]][rbt[s2]] = r;
        }

        floyd();
        bool flag = false;
        for (int i = 0; i < V; i++)
            if (d[i][i] > 1)
            {
                flag = true;
                break;
            }

        cout << "Case " << cas << ": ";
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}