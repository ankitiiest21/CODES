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
ll arr[N][N],I[N][N];

void multiply(ll a[][N],ll b[][N],ll m){
  ll res[m+1][m+1];
  REP(i,0,m){
    REP(j,0,m){
      res[i][j]=0;
      REP(k,0,m)
       res[i][j]=(res[i][j]+(a[i][k]%mod)*(b[k][j]%mod))%mod;
    }
  }
  REP(i,0,m)
   REP(j,0,m)
    a[i][j]=res[i][j];
}

void power(ll a[][N],ll m,ll n){
  REP(i,0,m){
    REP(j,0,m){
      if(i==j) I[i][j]=1;
      else I[i][j]=0;
    }
  }
  //For Naive Approach O(m^3*n)--->
  /*REP(i,0,n)
   multiply(I,a,m);*/

  //For Optimised approach O(m^3*log n)--->
  while(n){
    if(n%2)
      multiply(I,a,m),n--;
    else
      multiply(a,a,m),n/=2;
  }
  REP(i,0,m)
   REP(j,0,m)
    a[i][j]=I[i][j];
}

int main()
{
  ll t; cin>>t;
  while(t--){
    ll m,n;
    cin>>m>>n;
    REP(i,0,m)
     REP(j,0,m)
      cin>>arr[i][j];
    power(arr,m,n);
    REP(i,0,m){
      REP(j,0,m)
      cout<<arr[i][j]<<" ";
      NL;
    }
     
  }
  return 0;
}
