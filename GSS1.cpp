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
#define sl set<ll>
#define msl multiset<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vc vector<char>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
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
#define MAX (1<<16)
#define MAX2 (MAX<<2)
vl v(MAX);

struct segT {
  ll bestLeftSum,bestRightSum,bestSum,sum;
  void merge(segT &a,segT &b)
  {
   sum=a.sum+b.sum;
   bestLeftSum=max(a.bestLeftSum,a.sum+b.bestLeftSum);
   bestRightSum=max(a.bestRightSum+b.sum,b.bestRightSum);
   bestSum=max(max(a.bestSum,b.bestSum),a.bestRightSum+b.bestLeftSum);
  }
};

segT st[MAX2];

void buildTree(ll si,ll ss,ll se){
  if(ss==se){
    st[si].bestSum=st[si].bestRightSum=st[si].bestLeftSum=st[si].sum=v[ss];
    return;
  }
  ll mid=(ss+se)/2;
  buildTree(2*si,ss,mid);
  buildTree(2*si+1,mid+1,se);
  st[si].merge(st[2*si],st[2*si+1]);
}

void query(segT &s,ll si,ll ss,ll se,ll qs,ll qe){
  if(qs==ss&&qe==se){
    s=st[si];
    return;
  }
  else{
    ll mid=(ss+se)/2;
    if(mid>=qe)
      query(s,2*si,ss,mid,qs,qe);
    else if(mid<qs)
      query(s,2*si+1,mid+1,se,qs,qe);
    else{
      segT left,right;
      query(left,2*si,ss,mid,qs,qe);
      query(right,2*si+1,mid+1,se,qs,qe);
      s.merge(left,right);
    }
  }
}

int main()
{
 // #ifndef ONLINE_JUDGE
 //  freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout);
 //  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,m,l,r;
  cin>>n;
  REP(i,0,n)
   cin>>v[i];
  buildTree(1,0,n-1);
  cin>>m;
  segT ans;
  while(m--){
    cin>>l>>r;
    query(ans,1,0,n-1,l-1,r-1);
    cout<<ans.bestSum<<"\n";
  }
  return 0;
}
