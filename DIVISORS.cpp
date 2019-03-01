#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
#define ll long long int
#define vl vector<ll>
#define sl set<ll>
using namespace std;
int main()
{
 ll n,num1,num2=1,temp=0;
 cin>>n;
 ll a[n],count[1000005]={0};
 for(ll i=0;i<n;i++)
 {
  cin>>a[i];
  count[a[i]]++;
 }
 sort(a,a+n);
 num1=a[n-1];
 temp=num1;
 for(ll i=n-2;i>=0;i--)
 {	
  if(num1%a[i]!=0||count[a[i]]==2)
   {
    num2=a[i];
    break;
   }
 }
 cout<<num1<<" "<<num2<<endl;
 return 0;
}
