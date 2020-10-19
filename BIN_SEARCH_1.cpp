// Assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// n - number of stalls, c - number of cows.


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
ll n,c,a[100009];

bool check(ll mid){
  ll cnt=0,prev=INT_MIN;
  REP(i,0,n){
    if(a[i]-prev>=mid)
      cnt++,prev=a[i];
  }
  return cnt>=c;
}

ll solve(){
  ll s=1,e=a[n-1]-a[0],ans=0;
  while(s<=e){
    ll mid=s+(e-s)/2;
    if(check(mid))
      s=mid+1,ans=max(ans,mid);
    else
      e=mid-1;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t; cin>>t;
  while(t--){
    cin>>n>>c;
    REP(i,0,n)
     cin>>a[i];
    sort(a,a+n);
    cout<<solve()<<endl;
  }
  return 0;
}
