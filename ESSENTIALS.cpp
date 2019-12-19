  #include<bits/stdc++.h>
  using namespace std;
  #define ll long long
  
 ------------------------------------------CALCULATE (a^b)%m-----------------------------------------------------------------------
  
   ll mypow(ll a,ll b)
  {
    ll m=mod;
    ll mul=a,ans=1;
    while(b)
    {
     if(b&1)
     {
      ans*=mul;
      ans%=m;
     }
     mul*=mul;
     mul%=m;
     b/=2;
    }
   return ans%m;
  }

  
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

Catalan number C(n)=(1/(n+1))*calculateNCR(2*n,n);
