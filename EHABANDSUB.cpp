#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<bits/stdc++.h>
#include<string.h>
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
 ll n,k,x,mini=0,i;
 cin>>n>>k;
 sl s;
 for(ll i=0;i<n;i++)
 {
  cin>>x;
  s.insert(x);
 }
 //for(auto i=s.begin();i!=s.end();i++)
  //cout<<*i<<endl;
 mini=min((ll)s.size(),k);
 auto it=s.begin(),prev=s.begin();
 ll temp=k;
 for(ll i=0;i<mini;i++)
 {
  if(it==s.begin())
   cout<<*it<<endl;
  else
   {
    cout<<*it-*prev<<endl;
   }
   prev=it; 
   it++;
   temp--;  
 }
 while(temp--)
   {
    cout<<0<<endl;
   }
 return 0;
}
  
 