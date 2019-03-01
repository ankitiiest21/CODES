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
 char ch;	
 ll n,m;
 cin>>n>>m;
 set<char> sc;
 for(ll i=0;i<n*m;i++)
 {
  cin>>ch;
  sc.insert(ch);	
 }
 int C=count(sc.begin(),sc.end(),'C');
 int M=count(sc.begin(),sc.end(),'M');
 int Y=count(sc.begin(),sc.end(),'Y');
 if(C+M+Y==0)
  cout<<"#Black&White"<<endl;
 else
  cout<<"#Color"<<endl;  	
 return 0;
}