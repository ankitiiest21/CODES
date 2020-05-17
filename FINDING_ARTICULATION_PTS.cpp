#include<iostream>
#include<bits/stdc++.h> 
#include<string>
#include<map>
#include<time.h>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long int
#define ld long double
#define pl pair<ll,ll>
#define vl vector<ll>
#define sl set<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define ss set<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define INF (ll)10000000000
#define mod (ll)1000000007
using namespace std;
vl graph[100005];
ll visited[100005],in[100005],low[100005],timer;
sl CutVertex;
void addedge(ll a,ll b){
	graph[a].PB(b);
	graph[b].PB(a);
}


void insertCutVertex(ll node){
	CutVertex.IN(node);
}
void dfs(ll node,ll par){
	ll children = 0;
	in[node] = timer;
	low[node] = timer;
	timer++;
	visited[node] = true;
	for(auto child:graph[node]){
	 if(child==par)
	 	continue;
	 if(visited[child]){
       low[node] = min(low[node], in[child]);
	 }
	 else{
       dfs(child,node);
       low[node]=min(low[node],low[child]);
       if(par!=-1&&in[node]<=low[child])
       	 insertCutVertex(node);
       children++;
	 }
	}
	if(par==-1&&children>1)
		insertCutVertex(node);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll n,e,a,b;
    cin>>n>>e;
    REP(i,1,n+1)
     in[i]=0,low[i]=0,visited[i]=false,graph[i].clear();
    REP(i,0,e){
    	cin>>a>>b;
    	addedge(a,b);
    }
    CutVertex.clear();
    timer=0;
    dfs(1,-1);
    cout<<"The Cut Vertices is/are: ";
    REPIT(it,CutVertex)
     cout<<*it<<" ";
     cout<<endl;
	return 0;
}	
