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
ll f[1][2],n,M[2][2],I[2][2];

void multiply(ll a[][2],ll b[][2]){
  ll res[2][2];
  REP(i,0,2){
    REP(j,0,2){
      res[i][j]=0;
      REP(k,0,2)
       res[i][j]=(res[i][j]+(a[i][k]%mod)*(b[k][j]%mod))%mod;
    }
  }
  REP(i,0,2)
   REP(j,0,2)
    a[i][j]=res[i][j];
}

void findnthfib(){
  M[0][1]=M[1][0]=M[1][1]=I[0][0]=I[1][1]=1;
  M[0][0]=I[0][1]=I[1][0]=0;
  while(n){
    if(n%2)
      multiply(I,M),n--;
    else
      multiply(M,M),n/=2;
  }
  int f1=f[0][0],f2=f[0][1];
  f[0][0]=(((f1%mod)*(I[0][0]%mod))%mod+((f2%mod)*(I[1][0]%mod))%mod)%mod;
  f[0][1]=(((f1%mod)*(I[0][1]%mod))%mod+((f2%mod)*(I[1][1]%mod))%mod)%mod;
}

int main()
{
  ll t; cin>>t;
  while(t--){
    cin>>f[0][0]>>f[0][1]>>n; 
    findnthfib();
    cout<<f[0][0]<<endl;
  }
  return 0;
}
