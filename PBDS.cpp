#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long

using namespace std;
using namespace __gnu_pbds;

//Works as a set
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

//Works as a multiset
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> pbdsm;


int main()
{
 #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  pbds St;
  St.insert(99);
  St.insert(1);
  St.insert(10);
  St.insert(34);
  St.insert(7);

  for(int i=0;i<St.size();i++)
  	cout<<i<<" , "<<*St.find_by_order(i)<<endl;

  cout<<St.order_of_key(56)<<endl;

  pbdsm Stm;
  Stm.insert({99,0});
  Stm.insert({99,1});
  Stm.insert({1,2});
  Stm.insert({67,3});
  Stm.insert({1,4});
  Stm.insert({5,5});
  Stm.insert({45,6});
  Stm.insert({5,7});
  Stm.insert({45,8});

  for(int i=0;i<Stm.size();i++)
  	cout<<i<<" , "<<Stm.find_by_order(i)->first<<" , "<<Stm.find_by_order(i)->second<<endl;

   //Three cases arise while searching-
  // Case-1: If the element does not exist- we can pass any value as second
   cout<<Stm.order_of_key({57,94})<<endl;
   // Case-2: If the element exists- be careful while passing second value. It returns as per lower_bound(first) then as per lower_bound(second).
   cout<<Stm.order_of_key({5,6})<<endl;

  return 0;
}
