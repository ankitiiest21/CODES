#include<bits/stdc++.h>
#define EB emplace_back

using namespace std;
int makeSieve(int n)
{
 bool isPrime[n+1];
 for(int i=0;i<n+1;i++)
  isPrime[i]=true;
 isPrime[0]=false;
 isPrime[1]=false;
 for(int i=2;i*i<=n;i++)
 {
  if(isPrime[i]==true)
  {
   for(int j=i*i;j<=n;j+=i)
    isPrime[j]=false;	
  }	
 }
 cout<<"Number"<<"       "<<"Property"<<endl;
 for(int i=0;i<=n;i++)
  cout<<" "<<i<<"        "<<((isPrime[i]==true)?"Prime":"Composite")<<endl;  
 return count(isPrime,isPrime+n+1,true);  	
}
int main()
{
 int n;
 cin>>n;
 int c=makeSieve(n);
 cout<<"Number of Primes :"<<c<<endl;
 return 0;	
}
