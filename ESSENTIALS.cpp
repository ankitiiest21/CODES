  #include<bits/stdc++.h>
  using namespace std;
  #define ll long long
  
  -----------------------------------------CALCULATE nCr---------------------------------------------------------------------------
  
  
  ll calculateNCR(ll n,ll r){
   ll ans=1;
   if(r>n-r)
    r=n-r;
   for(ll i=0;i<r;i++){
    ans*=(n-i);
    ans/=(i+1);
   }
   return ans;
  }
