#include <bits/stdc++.h>
using namespace std;

class Triplet
{
 public: 
 	    int x;
 	    int y;
 	    int gcd;
};
Triplet ExtendedEuclid(int a,int b)
{
 //BASE CASE	
 if(b==0)
 {
  Triplet ans;
  ans.gcd=a;
  ans.x=1;
  ans.y=0;
  return ans;
 }
 Triplet Smallans=ExtendedEuclid(b,a%b);
 Triplet ans;
 ans.gcd=Smallans.gcd;
 ans.x=Smallans.y;
 ans.y=Smallans.x-(a/b)*Smallans.y;
 return ans;
}
int main() 
{
	ios::sync_with_stdio(false);
	int a,b;
	cin>>a>>b;
	Triplet ans=ExtendedEuclid(a,b);
	cout<<"x: "<<ans.x<<endl;
	cout<<"y: "<<ans.y<<endl;
	cout<<"GCD: "<<ans.gcd<<endl;
	return 0;
}
