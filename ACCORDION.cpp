#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#define ll long long int
#define vl vector<ll>
#define sl set<ll>
using namespace std;
int main()
{
 string s;
 cin>>s;
 ll n=s.size();
 ll count=0;
 bool b1=false;
 bool b2=false;
 bool b3=false;
 bool b4=false;
 ll i=0;
 while(i<n)
 {
 	if(s[i]=='[')
 	{
 	 b1=true;
 	 break;	
 	}
   i++;
 }
 ll sb=i;
 i=n-1;
 while(i>sb)
 {
 	if(s[i]==']')
 	{
 	 b2=true;
 	 break;	
 	}
 	i--;
 }
 ll cb=i;
 i=sb+1;
 if(b1&&b2)
 {
  while(i<cb)
  {
  	if(s[i]==':')
  	{
  	 b3=true;
  	 break;	
  	}
  	i++;	
  }
  ll sc=i;
  i=cb-1;
  while(i>sc)
  {
  	if(s[i]==':')
  	{
  	  b4=true;
  	  break;	
  	}
  	i--;
  }
  ll cc=i;
  if(b3&&b4)
  {
   for(ll i=sc+1;i<cc;i++)
   {
   	if(s[i]=='|')
   	 count++;	
   }
   cout<<count+4<<endl;
  }
  else
   cout<<-1<<endl;	
 }
 else
  cout<<-1<<endl;	
 return 0;
}