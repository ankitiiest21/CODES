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
 ll k,a[26]={0};	
 string s;
 set<char> sc;
 cin>>s>>k;
 for(ll i=0;i<s.length();i++)
 {
  sc.insert(s[i]);
 }
 if(sc.size()>=k)
  cout<<0<<endl;
 else
 {
  if(sc.size()==26)
   return cout<<"impossible"<<endl,0;
  if(s.length()<k)
  	return cout<<"impossible"<<endl,0;
   cout<<k-sc.size()<<endl; 	
 } 	
 return 0;
}
 