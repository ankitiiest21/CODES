    #include<iostream>
    #include<bits/stdc++.h> 
    #include<string>
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
    #define N (ll)10000
    #define mod (ll)1000000007
    using namespace std;
    vl graph[1000009];
    ll dist[1000009];
    bool visited[1000009]={false};
    const int maxN = 10;
    ll LCA[10001][maxN+1],level[10001];
    void addedge(ll a,ll b){
      graph[a].PB(b);
      graph[b].PB(a);
    }
    // void bfs(ll node){
    //     queue<ll> q;
    // 	ll curr=node;
    // 	visited[node]=true;
    // 	dist[node]=0;
    // 	q.push(node);
    // 	while(!q.empty()){
    // 		curr=q.front();
    // 		q.pop();
    // 		for(auto child:graph[curr]){
    // 			if(!visited[child]){
    // 				q.push(child);
    // 				visited[child]=true;
    // 				dist[child]=dist[curr]+1;
    // 				level[dist[child]]++;
    // 			}
    // 		}
    // 	}
    // }
    void dfs(ll node,ll lvl,ll par){
        level[node]=lvl;
        LCA[node][0]=par;
        for(ll child:graph[node]){
            if(child!=par){
                dfs(child,lvl+1,node);
            }
        }
    }
    void init(ll n){
        dfs(1, 0 , -1);
        for(int j=1;j<=maxN;j++){
            for(int i=1;i<=n;i++){
                if(LCA[i][j-i]!=-1){
                    int par = LCA[i][j-1];
                    LCA[i][j] = LCA[par][j-1];
                }
            }
        }
    }

    ll getLCA(ll a,ll b){
        if(level[a]>level[b]) swap(a,b);
        ll d = level[b] - level[a];
        while(d>0){
            int i = log2(d);
            b = LCA[b][i];
            d-=1<<i;
        }
        if(a==b) return a;
        for(int i=maxN;i>=0;i--){
            if((LCA[a][i]!=-1)&&(LCA[a][i]!=LCA[b][i])){
                a = LCA[a][i];
                 b = LCA[b][i];
            }
        }
        return LCA[a][0];
    }



    ll getDist(ll a,ll b){
        ll lca = getLCA(a,b);
        return level[a]+level[b]-2*level[lca];
    }
    int main()
    {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll v,e,a,b,q;
    cin>>v;
    REP(i,1,v+1){
        REP(j,0,maxN+1)
         LCA[i][j]=-1;
    }
    e=v-1;
    REP(i,0,e){
    	cin>>a>>b;
    	addedge(a,b);
    }
    init(v);
    cin>>q;
    REP(i,0,q){
     cin>>a>>b;
     cout<<getDist(a,b)<<endl;
    }
    return 0;
    }
