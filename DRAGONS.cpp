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
 ll s,n;
 cin>>s>>n;
 ll a[n],b[n];
 vector<pair<ll,ll> > vp;
 for(ll i=0;i<n;i++)
 {
  cin>>a[i]>>b[i];
  vp.push_back(make_pair(a[i],b[i]));
 }
 sort(vp.begin(),vp.end());
 for(ll i=0;i<n;i++)
 {
  if(vp[i].first<s)
   s+=vp[i].second;
  else
   return cout<<"NO"<<endl,0;
 }
 cout<<"YES"<<endl;  
 return 0;
}