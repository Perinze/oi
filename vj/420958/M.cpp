#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int k;

int word()
{
    char c;
    int ans = 0;
    while ((c = getchar()) != EOF) {
        ans++;
        if (c == ' ' || c == '-') return ans;
    }
    if (ans != 0)
        return ans - 1;
    return -1;
}

bool C(int w)
{
    int len = 0;
    int nl = 0;
    for (int i = 0; i < v.size(); i++) {
        if (w - len >= v[i]) {
            len += v[i];
        } else if (v[i] > w) {
            return false;
        } else {
            nl++;
            len = v[i];
        }
    }
    nl++;
    return nl <= k;
}

int main()
{
    scanf("%d\n", &k);
    int len;
    int cnt = 0;
    int mlen = 0;
    while ((len = word()) != -1) {
        v.push_back(len);
        cnt += len;
        mlen = max(mlen, len);
    }
    int l = mlen, r = cnt;
    int ans;
    while (r - l >= 0) {
        int mid = (l + r) / 2;
        if (C(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}