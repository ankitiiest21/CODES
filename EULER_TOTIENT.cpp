// Euler Totient Function counts the number of integers lesser than N which are coprime to N
// ETF(N) = N*(p1-1)*(p2-1)*(p3-1)*....*(pk-1) / p1*p2*p3*...*pk where p1,p2,p3,..,pk are the prime divisors of N.
// phiOsqrt works in O(sqrt N) for each N.
// init(n) does preprocessing of all phi[i] values for each i<= a certain extent(10^6).
// init(n) works in O(nlog(log n)) by using sieve. 
// phi[i] is initialized to i for every i. Whenever we find phi[i] == i, we are certain that i is a prime number and do accordingly to subsequent multiples of i.

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
ll phi[1000007];

void init(ll n){
 REP(i,1,n+1)
  phi[i]=i;
 REP(i,2,n){
  if(phi[i]==i){
    for(ll j=i;j<=n;j+=i){
      phi[j]/=i;
      phi[j]*=(i-1);
    }
  }
 }
}

ll phiOsqrtn(ll n){
  ll res=n;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      res/=i;
      res*=(i-1);
      while(n%i==0)
        n/=i;
    }
  }
  if(n>1)
    res/=n,res*=(n-1);
  return res;
}
 


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  init(1000000);
  ll t=1; 
  cin>>t;
  while(t--){ 
    ll n;
    cin>>n;
    cout<<"ETF("<<n<<"): "<<phiOsqrtn(n)<<endl;
    cout<<"ETF("<<n<<"): "<<phi[n]<<endl;
  }
  return 0;
}
