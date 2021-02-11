#include <cstdio>
#include <set>
using namespace std;

char cmd()
{
    char c;
    while ((c = getchar()) != EOF)
        if (c == '+' || c == '-')
            return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c = cmd();
        int id;
        scanf("%d", &id);
        if (c == '+') {
            s.insert(id);
            int len = s.size();
            ans = max(ans, len);
        } else {
            if (s.find(id) == s.end()) {
                ans++;
            } else {
                s.erase(id);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}