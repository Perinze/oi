#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int N = 10000010;

char convert(char ch) {
    switch (ch) {
        case '0': return '0';
        case '1': return '1';
        case '2': return '2';
        case '3': 
        case '4': return '3';
        case '5': return '4';
        case '6':
        case '7':
        case '8':
        case '9': return '5';
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F': return '6';
        case '.': return '7';
    }
    return '8';
}

int max_to[N], max_from[N];
struct Trie 
{
    int next[N][10], fail[N], end[N], len[N];
    int root, L;
    int newNode() {
        for (int i=0; i<10; i++) {
            next[L][i] = -1;
        }
        end[L] = 0;
        len[L++] = 0;
        return L-1;
    }

    void init() {
        L = 0;
        root = newNode();
    }

    void insert(string buf) {
        int l = buf.length();
        int now = root;
        for (int i=0; i<l; i++) {
            int tmp1 = buf[i] - '0';
            if (next[now][tmp1] == -1) {
                next[now][tmp1] = newNode();
            }
            now = next[now][tmp1];
        }
        end[now]++;
        len[now] = max(len[now], l);
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i=0; i<10; i++) {
            if (next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        int tmp2;
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            tmp2 = fail[now];
            for (int i=0; i<10; i++) {
                if (next[now][i] == -1) {
                    next[now][i] = next[tmp2][i];
                } else {
                    fail[next[now][i]] = next[tmp2][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    int query(char buf[]) {
        int l = strlen(buf);
        int now = root;
        int res = 0;
        for (int i=0; i<l; i++) {
            now = next[now][convert(buf[i])-'0'];
            int tmp = now;
            while (tmp != root) {
                max_from[i] = max(max_from[i], len[tmp]);
                tmp = fail[tmp];
            }
        }
        return res;
    }   
} ac;

void buildTrie() {
    set<string> s;
    for (int i=0; i<256; i++) {
        string str = "";
        int t = i;
        do {
            str += convert(t%10+'0');
            t /= 10;
        } while (t);
        reverse(str.begin(), str.end());
        s.insert(str);
        str = "";
        t = i;
        do {
            int p = t % 16;
            if (p < 10) p += '0';
            else p += 'A'-10;
            str += convert(p);
            t /= 16;
        } while (t);
        reverse(str.begin(), str.end());
        s.insert(str);
    }
    
    ac.init();

    int siz = s.size();
    for (auto s1: s) {
        for (auto s2: s) {
            string str = s1+'7'+s2;
            ac.insert(str);     
        }
    }    
    ac.build();
}

char passage[N];

int main() {
    // freopen("ip.in", "r", stdin);
    // freopen("ip.out", "w", stdout);
    buildTrie();
    scanf("%s", passage);
    ac.query(passage);
    int len = strlen(passage);
    for (int i=len; i>0; i--) {
        max_to[i-max_from[i]+1] = max(max_to[i-max_from[i]+1], max_from[i]);
    }
    int pos = 0;
    while (pos < len) {
        if (max_to[pos] != 0) {
            int next = pos + max_to[pos];
            if (next < len-1 && passage[next] == '.' && max_to[next+1] != 0) {
                for (int i=pos; i<=next+max_to[next+1]; i++) {
                    printf("%c", passage[i]);
                }
                printf("\n");
            }
        }
        pos++;
    }
    //system("pause");
    return 0;
}