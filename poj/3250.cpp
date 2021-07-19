#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long ll;
const int maxn = 80010;
int n;
#ifdef STL
stack<int> stk;
#else
int stk[maxn], tp;
#endif

int main()
{
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
#ifdef STL
        while (!stk.empty() && stk.top() <= x) stk.pop();
        ans += stk.size();
        stk.push(x);
#else
        while (tp && stk[tp] <= x) tp--;
        ans += tp;
        stk[++tp] = x;
#endif
    }
    printf("%lld\n", ans);
    return 0;
}