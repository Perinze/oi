#include <iostream>
using namespace std;

int par[30000], rnk[30000];
int N, M;

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    ios::sync_with_stdio(false);
    for (;;)
    {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        init(N);
        for (int i = 0; i < M; i++)
        {
            int k; cin >> k;
            int lst; cin >> lst;
            for (int j = 1; j < k; j++)
            {
                int x; cin >> x;
                unite(lst, x);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
            if (same(0, i)) ans++;
        cout << ans << endl;
    }
    return 0;
}