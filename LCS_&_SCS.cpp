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
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define REV(a) reverse(a.begin(),a.end())
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)51
#define INF (ll)10000000000
#define mod (ll)1000000007 
using namespace std;




int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  string a,b;
  cin>>a>>b;
  ll n=a.size(),m=b.size();
  string lcs,scs;
  // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
  vector<vl> dp(n+1,vl (m+1,0));
  REP(i,1,n+1){
  	REP(j,1,m+1){
  		if(a[i-1]==b[j-1])
  			dp[i][j]=1+dp[i-1][j-1];
  		else
  			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  	}
  }
  ll i=n,j=m;
  while(i>0&&j>0){
  		if(a[i-1]==b[j-1])
  			scs+=a[i-1],lcs+=a[i-1],i--,j--;
  		else{
  			if(dp[i-1][j]>dp[i][j-1])
  				scs+=a[i-1],i--;
  			else
  				scs+=b[j-1],j--;
  		}
  }
  while(i>0)
  	scs+=a[i-1],i--;
  while(j>0)
  	scs+=b[j-1],j--;
  REV(lcs);
  REV(scs);
  cout<<"Longest Common Subsequence is: "<<lcs<<endl;
  cout<<"Shortest Common Supersequence is: "<<scs<<endl;
  return 0;
}
