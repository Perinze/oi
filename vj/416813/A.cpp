#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
using namespace std;
#define each(i, l, r) for (int i = l; i < r; i++)

int T;
int map[1000000];
int cas = 1;

/*
void print_list(list<int> l)
{
	for (auto ite = l.begin(); ite != l.end(); ite++)
		cout << *ite << ' ';
	cout << endl;
}
*/

bool solve()
{
    cin >> T;
	if (T == 0) return false;

    vector<queue<int> > Q(T);
    list<int> team;

    each(i, 0, T)
    {
        int nt;
        cin >> nt;
        each(j, 0, nt)
        {
            int elem;
            cin >> elem;
            map[elem] = i;
			//cout << elem << "->" << map[elem] << endl;
        }
    }

	cout << "Scenario #" << cas++ << endl;

    string cmd;
    for (;;)
    {
        cin >> cmd;
        if (cmd == "STOP") break;
        if (cmd == "ENQUEUE")
        {
            int num;
            cin >> num;
            int t = map[num];
			//cout << "enqueuing to " << t << " team" << endl;

            list<int>::iterator ite = team.begin();
			//print_list(team);
			while (ite != team.end())
			{
				if (*ite == t) break;
				ite++;
			}
			if (ite == team.end()) team.push_back(t);
			//print_list(team);

            Q[t].push(num);
        }
        else
        {
            int t = team.front();
			//cout << "team front is " << t << endl;
            int num = Q[t].front(); Q[t].pop();
            cout << num << endl;
            if (Q[t].size() == 0)
            {
                team.pop_front();
            }
        }
    }
	cout << endl;
	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while (solve());
    return 0;
}
