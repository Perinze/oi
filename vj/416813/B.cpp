#include <iostream>
#include <string>
#include <stack>
using namespace std;

int block[25][25];
int size[25];
pair<int, int> where[25];   // (x, y)

void mv(int pos, int to)  // move block on top of 'pos' to 'to'
{
    int b = block[pos][--size[pos]];
    where[b] = make_pair(to, size[to]);
    block[to][size[to]++] = b;
}

void re(int pos)  // return block on top of 'pos'
{
    int b = block[pos][--size[pos]];
    where[b] = make_pair(b, size[b]);
    block[b][size[b]++] = b;
}

void redir(int pos, int n) // return 'n' blocks on top of 'pos'
{
    for (int i = 0; i < n; i++) re(pos);
}

void mvdir(int pos, int n, int to)  // move 'n' blocks on top of 'pos' to 'to'
{
    stack<int> s;
    for (int i = 0; i < n; i++) s.push(block[pos][--size[pos]]);
    for (int i = 0; i < n; i++)
    {
        where[s.top()] = make_pair(to, size[to]);
        block[to][size[to]++] = s.top();
        s.pop();
    }
}

void CMD(int cmd, int a, int b)
{
    int pos_a = where[a].first;
    int pos_b = where[b].first;
    int height_a = where[a].second;
    int height_b = where[b].second;
    int above_a = size[pos_a] - height_a - 1;
    int above_b = size[pos_b] - height_b - 1;

    if (cmd == 0)
    {
        redir(pos_a, above_a);
        redir(pos_b, above_b);
        mv(pos_a, pos_b);
    }
    else if (cmd == 1)
    {
        redir(pos_a, above_a);
        mv(pos_a, pos_b);
    }
    else if (cmd == 2)
    {
        redir(pos_b, above_b);
        mvdir(pos_a, above_a + 1, pos_b);
    }
    else if (cmd == 3)
    {
        mvdir(pos_a, above_a + 1, pos_b);
    }
}

void print(int pos)
{
    cout << pos << ": ";
    for (int i = 0; i < size[pos]; i++) cout << block[pos][i] << ' ';
    cout << endl;
}

void print_all(int t)
{
    for (int i = 0; i < t; i++) print(i);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        where[i] = make_pair(i, 0);
        block[i][size[i]++] = i;
    }

    string cmd0, cmd1;
    int a, b;
    for (;;)
    {
        cin >> cmd0;
        if (cmd0 == "quit") break;
        cin >> a >> cmd1 >> b;
        if (a == b) continue;
        if (where[a].first == where[b].first) continue;
        int cmd = (cmd0 == "move"? 0: 2) + (cmd1 == "onto"? 0: 1);
        CMD(cmd, a, b);
        //print_all(t);
    }
    print_all(t);

    return 0;
}