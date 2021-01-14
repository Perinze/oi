#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=36;
int main()
{
    __int64_t a[MAX][MAX]={0};
    int i,j,n;
    for(i=1;i<MAX;i++)
        a[i][1]=1;
    for(i=1;i<MAX;i++)
        for(j=1;j<=i;j++)
        {
            if(i==j)
                a[i][j]+=a[i][j-1];
            else
                a[i][j]+=a[i-1][j]+a[i][j-1];
        }
    i=0;
	for (int i = 1; i < MAX; i++)
		cout << a[i][i] << endl;
    while(cin>>n&&n!=-1)
    {
        printf("%d %d %I64d\n",++i,n,2*a[n][n]);
    }
    return 0;
}
