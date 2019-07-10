//akki
#include<bits/stdc++.h>
using namespace std;
struct node{
	int maxi;
	int smaxi;
};
struct node query(node*tree,int treeInd,int s,int e,int l,int r)
{
 struct node h;
 if(s>r||e<l)
 {
  h.maxi=-1;
  h.smaxi=-1;
  return h;	
 }
 else if(s>=l&&e<=r)
  return tree[treeInd];
 int m=(s+e)/2;
 struct node left=query(tree,2*treeInd,s,m,l,r);
 struct node right=query(tree,2*treeInd+1,m+1,e,l,r);
 h.maxi=max(left.maxi,right.maxi);
 h.smaxi=min(max(left.smaxi,right.maxi),max(left.maxi,right.smaxi));
 return h; 	
}
void updateTree(int*a,node*tree,int treeInd,int s,int e,int ind,int val)
{
 if(s==e)
 {
  if(s==ind)
  {	
   a[ind]=val;
   tree[treeInd].maxi=val;
  }
  return;	
 }
 int m=(s+e)/2;
 if(ind>m)
  updateTree(a,tree,2*treeInd+1,m+1,e,ind,val);
 else
  updateTree(a,tree,2*treeInd,s,m,ind,val);
 node left=tree[2*treeInd];
 node right=tree[2*treeInd+1];
 tree[treeInd].maxi=max(left.maxi,right.maxi);
 tree[treeInd].smaxi=min(max(left.smaxi,right.maxi),max(right.smaxi,left.maxi));  	
}
void buildTree(int*a,node*tree,int treeInd,int s,int e)
{
 if(s==e)
 {
  tree[treeInd].maxi=a[s];	
  tree[treeInd].smaxi=INT_MIN;
  return;	
 }
 int m=(s+e)/2;
 buildTree(a,tree,2*treeInd,s,m);
 buildTree(a,tree,2*treeInd+1,m+1,e);
 node left=tree[2*treeInd];
 node right=tree[2*treeInd+1];
 tree[treeInd].maxi=max(left.maxi,right.maxi);
 tree[treeInd].smaxi=min(max(left.maxi,right.smaxi),max(left.smaxi,right.maxi));
 return;
}
int main()
{
 int n;
 cin>>n;
 int*a=new int[n];
 for(int i=0;i<n;i++)
  cin>>a[i];	
 node*tree=new node[3*n];
 buildTree(a,tree,1,0,n-1);
 for(int i=1;i<3*n;i++)
  cout<<tree[i].maxi<<" , "<<tree[i].smaxi<<endl;
 while(1)
 {
  int ch;	
  cout<<"Enter 1.Update 2.Query 3.Exit: ";
  cin>>ch;
  switch(ch)
  {
   case 1: int ind,val;
           cin>>ind>>val;
           updateTree(a,tree,1,0,n-1,ind-1,val);
           break;

   case 2: int l,r;
           cin>>l>>r;
           struct node ans;
           ans=query(tree,1,0,n-1,l-1,r-1);
           cout<<ans.maxi+ans.smaxi<<endl;
           break;
   default: exit(0);        
  }	
 }
return 0;
}
