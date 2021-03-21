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
#define PF push_front
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long
#define ld long double
#define pl pair<ll,ll>
#define ql queue<ll>
#define dql deque<ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define sl set<ll>
#define msl multiset<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vc vector<char>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define vvs vector<vector<string>>
#define ADD(a,sum) accumulate(a.begin(),a.end(),sum)
#define REV(a) reverse(a.begin(),a.end())
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)51
#define INF (ll)10000000000
#define mod (ll)1000000007 
using namespace std;

//POLYNOMIAL ROLLING HASH FUNCTION IS USED TO COMPUTE HASHES
ll calculate_hash(string const&s){
  ll p=31;
  ll m=1e9+9;
  ll p_pow=1;
  ll hash=0;
  for(char c:s){
    hash=(hash+p_pow*(c-'a'+1))%m;
    p_pow=(p_pow*p)%m;
  }
  return hash;
}

vvs findGroupsWithIdenticalStrings(vs v,ll n){
  vp hashes(n);
  REP(i,0,n){
    hashes[i]={calculate_hash(v[i]),i};
  }
  sort(hashes.begin(),hashes.end());
  vvs groups;
  REP(i,0,n){
    if(!i||hashes[i].first!=hashes[i-1].first)
      groups.emplace_back();
    groups.back().push_back(v[hashes[i].second]);
  }
  return groups;
}




int main()
{

  ll n;
  cin>>n;
  vs v(n);
  REP(i,0,n)
   cin>>v[i];
  vvs groups=findGroupsWithIdenticalStrings(v,n);
  REP(i,0,groups.size()){
    REP(j,0,groups[i].size())
     cout<<groups[i][j]<<" ";
    cout<<"\n";
  }
  return 0;
}
