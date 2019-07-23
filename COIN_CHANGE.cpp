#include<bits/stdc++.h>
using namespace std;
int coin_change(int*a,int n,int val,int**dp)
{
 if(n==0||val<0)
  return 0;
 if(val==0)
  return 1;
 if(dp[n][val]!=-1)
  return dp[n][val];
 int first=coin_change(a,n,val-a[0],dp);
 int second=coin_change(a+1,n-1,val,dp);
 dp[n][val]=first+second;
 return dp[n][val];   	
}
int main()
{
 int n,val;	
 cout<<"Enter number of denominations: ";
 cin>>n;
 int a[n];
 cout<<"Enter the denominations: "<<endl;
 for(int i=0;i<n;i++)
  cin>>a[i];
 cout<<"Enter the value to get changes: ";
 cin>>val;
 int**dp=new int*[n+1];
 for(int i=0;i<n+1;i++)
 {
  dp[i]=new int[val+1];
  for(int j=0;j<val+1;j++)
   dp[i][j]=-1;	
 }
 cout<<"No of ways to get changes for the value is: "<<coin_change(a,n,val,dp)<<endl;
 for(int i=0;i<n+1;i++)
 	delete []dp[i];
 delete []dp;
 return 0;
}
