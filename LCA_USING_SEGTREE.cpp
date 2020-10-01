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
#define N (ll)100009
#define INF (ll)10000000000
#define mod (ll)1000000007
using namespace std;
vl euler,height,first,segtree;
vector<bool> visited;

void dfs(vl tree[],ll node,ll h=0){
  visited[node]=true;
  height[node]=h;
  first[node]=euler.size();
  euler.push_back(node);
  for(auto child:tree[node]){
    if(!visited[child]){
      dfs(tree,child,h+1);
      euler.push_back(node);
    }
  }
}

void build(ll node,ll s,ll e){
  if(s==e){
    segtree[node]=euler[s];
  }
  else{
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    ll l=segtree[2*node];
    ll r=segtree[2*node+1];
    segtree[node]=((height[l]<height[r])?l:r);
  }
  
}


ll query(ll node,ll s,ll e,ll l,ll r){
  if(s>r||e<l)
    return -1;
  if(s>=l&&e<=r)
    return segtree[node];
  ll mid=(s+e)>>1;
  ll left=query(2*node,s,mid,l,r);
  ll right=query(2*node+1,mid+1,e,l,r);
  if(left==-1) return right;
  if(right==-1) return left;
  return height[left]<height[right]?left:right;
}

ll lca(ll a,ll b){
  ll l=first[a],r=first[b];
  if(l>r)
    swap(l,r);
  return query(1,0,euler.size()-1,l,r);
}

int main()
{
 // #ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
 // #endif
 ios::sync_with_stdio(0);
 cin.tie(0);
 ll t;
 cin>>t;
 REP(T,1,t+1){
  ll n,num,a,b,node,q; euler.empty(); visited.empty(); height.empty(); first.empty(); segtree.empty();
  cin>>n;
  height.resize(n+1);
  euler.reserve(n*n);
  first.resize(n+1);
  visited.resize(n+1);
  vl tree[n+1];
  REP(i,0,n){
    visited[i+1]=false;
   //For each node, num is the number of children
   cin>>num;
   //The below loop takes children as input and pushes it in the tree.
   while(num--){
    cin>>node;
    tree[i+1].PB(node);
    tree[node].PB(i+1);
   }
  }
  dfs(tree,1);
  ll m=euler.size(); 
  segtree.resize(4*m+1);
  build(1,0,m-1);
  cout<<"Case "<<T<<":\n";
  cin>>q;
  REP(i,1,q+1){
    cin>>a>>b;
    cout<<lca(a,b)<<endl;
  }
 }
 return 0;
}
