#include<bits/stdc++.h>
const int N=100001;
#define ll long long
using namespace std;
vector<ll> graph[N];
bool visited[N];
void addedge(ll u,ll v){
 graph[u-1].push_back(v-1);
 graph[v-1].push_back(u-1);
}

# DFS ----------------------------------------------------------------------------------------------------------------

void dfs(ll node){
 visited[node]=true;
 cout<<node+1<<" ";
 for(ll i:graph[node]){
  if(!visited[i])
   dfs(i);
  }
  return;
}

#BFS -------------------------------------------------------------------------------------------------------------------

void bfs(ll node){
 queue<ll> q;
 q.push(node);
 while(!q.empty()){
  ll cv=q.front();
  visited[cv]=true;
  cout<<cv+1<<" ";
  q.pop();
  for(ll i:graph[cv]){
   if(!visited[i]){
    q.push(i);
    visited[i]=true;
    }
   }
  }
  return;
 }

#Minimum Sum of Connected Components ------------------------------------------------------------------------------------

void dfs(ll node,ll a[],ll &mini){    //'a' is the array of weights  
	mini=min(mini,a[node]);
	visited[node]=true;
	for(ll i:graph[node]){
		if(!visited[i])
		 dfs(i,a,mini);
	}
}

ll MSCC(ll a[],ll n){     //'a' is the array of weights
	ll sum=0;
	for(ll i=0;i<n;i++){
		if(!visited[i]){
			ll mini=a[i];
			dfs(i,a,mini);
			sum+=mini;
		}
	}
	return sum;
}

 int main(){
 ll n,e;
 cin>>n>>e;
 for(ll i=0;i<e;i++){
 ll sv,ev;
 cin>>sv>>ev;
 addedge(sv,ev);
 }
 return 0;
 }
