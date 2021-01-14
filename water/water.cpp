#include <iostream>
#include <iomanip>
 using namespace std;
void main()
{ 
   const int n=2,m=3;
   float a[n][m],b[m][n];
   int i,j;
   cout<<"输入数组a"<<endl;   
   for(i=0;i<n;i++)     
	   for(j=0;j<m;j++)        
		   cin>>a[i][j];
   for(i=0;i<n;i++)
   {
	   for(j=0;j<m;j++)
	   {
		   cout<<setw(3)<<a[i][j];
		   b[j][i]=a[i][j];
	   }
	   cout<<endl;
   }
   cout<<"输出矩阵b"<<endl;
   for(i=0;i<m;i++)
   {
	   for(j=0;j<n;j++)
		   cout<<setw(3)<<b[i][j];
	   cout<<endl;
   }
}
