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
  ll n,anton=0,danik=0;
  cin>>n;
  string str;
  cin>>str;
  for(auto i=str.begin();i<str.end();i++)
  {
  	if(*i=='A')
  	 anton++;
  	else
  	 danik++;  	
  }
  cout<<((anton>=danik)?((anton==danik)?"Friendship":"Anton"):"Danik")<<endl;
  return 0;
}