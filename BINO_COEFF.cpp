// Finding nCr % p using Fermat's Little theorem. For details refer to MOD_INV.cpp

#include<iostream>
#include<bits/stdc++.h> 
#include<limits.h>
#include<string>
#include<map>
#include<time.h>
#include<queue>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long
#define ld long double
#define pl pair<ll,ll>
#define ql queue<ll>
#define vl vector<ll>
#define sl set<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)51
#define INF (ll)10000000000
#define mod (ll)1000000007 
using namespace std;
ll fac[1000001];


ll power(ll a,ll n,ll d){
  ll res=1;
  while(n){
    if(n%2)
      res=((res%d)*(a%d))%d,n--;
    else
      a=((a%d)*(a%d))%d,n/=2;
  }
  return res;
}
 


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  fac[0]=fac[1]=1;
  REP(i,2,1000001)
   fac[i]=(fac[i-1]*i)%mod;
  ll t=1; 
  cin>>t;
  while(t--){
   ll n,r;
   cin>>n>>r;
   ll res=fac[n];
   res=(res*power(fac[r],mod-2,mod))%mod;
   res=(res*power(fac[n-r],mod-2,mod))%mod;
   cout<<res<<endl;
  }
  return 0;
}
