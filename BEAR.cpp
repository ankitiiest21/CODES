#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#define ll long long int
#define ld long double
#define vl vector<ll>
#define sl set<ll>
using namespace std;
int main()
{
 ll n,a,sum=0,ind;
 cin>>n>>a;
 ll b[n];
 for(ll i=0;i<n;i++)
 {
  cin>>b[i];
  if(i<=a-1)
  {
   if(b[i]==1)	
    sum++;
  }
  if(i>a-1)
  {
   ind=i-a+1;	
   if(b[i]==1)
   {
   	
   	if(a-ind-1>=0)
   	{
   	 if(b[a-ind-1]==1)
   	  sum++; 	
   	}
   	else
   	 sum++;	
   }
   else
   {
   	if(a-ind-1>=0)
   	{
   	 if(b[a-ind-1]==1)
   	  sum--;	
   	}
   }	
  }
}
cout<<sum<<endl;

 return 0;
 }  	