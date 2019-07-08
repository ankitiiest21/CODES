//akki
#include<bits/stdc++.h>
using namespace std;
int query(int*tree,int s,int e,int l,int r,int treeNode)
{
 //Completely outside the given range
 if(s>=r||e<=l)
  return 0;
//Completely inside the given range
 if(s>=l&&e<=r)
  return tree[treeNode];
 //Partially inside and outside the given range
 int m=(s+e)/2;
 int ans1=query(tree,s,m,l,r,2*treeNode);
 int ans2=query(tree,m+1,e,l,r,2*treeNode+1);
 return ans1+ans2;
 
}
void updateTree(int*a,int*tree,int s,int e,int treeNode,int ind,int val)
{
 if(s==e)
 {
  a[ind]=val;
  tree[treeNode]=val;
  return;	
 }
 int m=(s+e)/2;
 if(ind>m)
  updateTree(a,tree,m+1,e,2*treeNode+1,ind,val);
 else
  updateTree(a,tree,s,m,2*treeNode,ind,val);
 tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];	
}
void buildTree(int*a,int*tree,int s,int e,int treeNode)
{
 if(s==e)
 {
  tree[treeNode]=a[s];
  return;	
 }	
 int m=(s+e)/2;
 buildTree(a,tree,s,m,2*treeNode);
 buildTree(a,tree,m+1,e,2*treeNode+1);
 tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
  cin>>a[i];
 int*tree=new int[2*n];
 buildTree(a,tree,0,n-1,1);
 for(int i=1;i<2*n;i++)
  cout<<tree[i]<<" ";
 int ind,val;
 cin>>ind>>val;
 updateTree(a,tree,0,n-1,1,ind,val);
 cout<<"Status of tree after update: "<<endl;
  for(int i=1;i<2*n;i++)
  cout<<tree[i]<<" ";
 int l,r;
 cin>>l>>r;
 int ans=query(tree,0,n-1,l,r,1);
 cout<<"Answer of the Query: "<<ans<<endl;
 return 0; 	
}
