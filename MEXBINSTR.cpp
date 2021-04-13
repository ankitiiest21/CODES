// MEX(S) is the smallest non-negative integer without leading zeros such that it is not a subsequence of S....

#include<iostream>
#include<bits/stdc++.h> 

#define vl vector<ll>

#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)

#define INF (ll)10000000000

using namespace std;


int main()
{
  ll t=1;
  cin>>t;
  while(t--)
  {
   string s;
   cin>>s;
   ll n=s.size();
    
   // next0[i] stores the index of the nearest 0 occuring after index i.
   // next1[i] stores the index of the nearest 1 occuring after index i.
    
   vl next0(n,INF),next1(n,INF);
   ll n0=INF,n1=INF;
   REPI(i,0,n){
    next0[i]=n0;
    next1[i]=n1;
    if(s[i]=='1') 
      n1=i;
    else
      n0=i;
   }
   if(n0==INF)   // Case - No '0' occurs in the binary string s
    cout<<"0\n";
   else if(n1==INF)  // Case - No '1' occurs in the binary string s
    cout<<"1\n";
   else
   {
     
    // dp[i] = longest length of binary string which is a subsequence of s[i+1:n]
    // e.g.- if dp[i]=2, it means all binary strings of length 2 (00,01,10,11) is a subsequence of s[i+1:n]
     
    vl dp(n,0);
    bool one=false,zero=false;
    ll cnt=0;
    REPI(i,0,n){
      dp[i]=cnt;
      if(s[i]=='1')
        one=true;
      if(s[i]=='0')
        zero=true;
      if(one&&zero){
        cnt++;
        one=zero=false;
      }
    }
    string ans="";
    // We can always claim that ans will start with '1'
    ll curr=n1;
    while(1){
      ans+=s[curr];
      // After adding character at index curr, we have to see the next0[curr] and next1[curr]  
      ll p0=next0[curr],p1=next1[curr];
      // if no '0' occurs in the string further to curr
      if(p0==INF){
        ans+='0';
        break;
      }
      // if no '1' occurs in the string further to curr
      else if(p1==INF){
        ans+='1';
        break;
      }
      else{
        // if dp[next0[curr]] <= dp[next1[curr]], we will greedily append ans with '0' as we need the minimum non-negative integer
        if(dp[p0]<=dp[p1])
          curr=p0;
        else
          curr=p1;
      }
    }
    cout<<ans<<endl;
   }
  }
  return 0;
}
