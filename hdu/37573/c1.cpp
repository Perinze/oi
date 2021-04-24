#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1e6+10;
struct node
{
    int val,idx;
}c[N];
int BIT[N];
int lowbit(int x){return x&(-x);}
void update(int x,int n)
{
    while(x<=n){
        BIT[x]+=1;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int sum=0;
    while(x>=1){
        sum+=BIT[x];
        x-=lowbit(x);
    }
    return sum;
}
bool cmp(node x,node y){return x.val>y.val;}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i].val);
            c[i].idx=i;
        }
        sort(c+1,c+1+n,cmp);
        int cnt=0;
        for(int i=1;i<=n;i++){
            update(c[i].idx,n);
            cnt+=query(c[i].idx-1);
        }
        printf("%d\n",cnt);
    }
    return 0;
}