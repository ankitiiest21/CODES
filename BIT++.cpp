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
 ll n,val=0;
 cin>>n;
 while(n--)
 {
  string str;
  cin>>str;
  for(auto i=str.begin();i<str.end();i++)
  {
  	if(*i=='+'||*i=='-')
  	{
  	  val+=(*i=='+')?1:-1;
  	  break;
  	}
  }
 }
 cout<<val<<endl;
 return 0;
}