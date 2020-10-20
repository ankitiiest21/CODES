// Finding modulo multiplicative inverse
// By Fermat's Little theorem, for a prime m and a number x such that gcd(a,m) = 1
// a^(m-1) congruent to 1 (mod m)
// a^(m-2) congruent to a^(-1) (mod m)
// So Finding modulo multiplicative inverse of a , under modulo m is same as finding a^(m-2) (mod m)

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

ll power(ll a,ll m,ll p){
 ll res=1;
 while(m){
   if(m%2) 
    res=(res*a)%p,m--;
   else
    a=(a*a)%p,m/=2;
 }
 return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t=1; 
  cin>>t;
  while(t--){
   ll x,m;
   cin>>x>>m;
   cout<<"a^-1 % m: "<<power(x,m-2,m)<<endl;
  }
  return 0;
}
