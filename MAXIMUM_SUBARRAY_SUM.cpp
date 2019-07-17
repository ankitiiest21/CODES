//akki
#include<bits/stdc++.h>

using namespace std;
struct segtree{
	int maxSum;
	int sum;
	int BPS;
	int BSS;
};

void buildtree(int*a,segtree*tree,int s,int e,int treeNode)
{
  if(s==e)
  {
   tree[treeNode].maxSum=a[s];	
   tree[treeNode].sum=a[s];
   tree[treeNode].BPS=a[s];
   tree[treeNode].BSS=a[s];
   return;	
  }	
  int m=(s+e)/2;
  buildtree(a,tree,s,m,2*treeNode);
  buildtree(a,tree,m+1,e,2*treeNode+1);
  segtree left=tree[2*treeNode];
  segtree right=tree[2*treeNode+1];
  tree[treeNode].sum=left.sum+right.sum;
  tree[treeNode].maxSum=max(left.maxSum,max(right.maxSum,max(left.sum+right.BPS,max(right.sum+left.BSS,max(left.sum+right.sum,left.BSS+right.BPS)))));
  tree[treeNode].BPS=max(left.BPS,left.sum+right.BPS);
  tree[treeNode].BSS=max(right.BSS,right.sum+left.BSS);
  return;
}


struct segtree query(segtree*tree,int s,int e,int treeNode,int l,int r)
{
 if(s>r||e<l)
 {
  struct segtree a;
  a.maxSum=-999999;
  a.sum=0;
  a.BPS=-999999;
  a.BSS=-999999;
  return a;
 }
 if(s>=l&&e<=r)
  return tree[treeNode];
 int m=(s+e)/2;
 struct segtree left=query(tree,s,m,2*treeNode,l,r);
 struct segtree right=query(tree,m+1,e,2*treeNode+1,l,r);
 struct segtree ans;
 ans.sum=left.sum+right.sum;
 ans.maxSum=max(left.maxSum,max(right.maxSum,max(left.sum+right.sum,max(left.sum+right.BPS,max(right.sum+left.BSS,left.BSS+right.BPS)))));
 ans.BPS=max(left.BPS,left.sum+right.BPS);
 ans.BSS=max(right.BSS,right.sum+left.BSS);
 return ans;	
}

int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
  cin>>a[i];
 segtree*tree=new segtree[4*n];
 buildtree(a,tree,0,n-1,1);
 int m;
 cin>>m;
 while(m--)
 {
  int l,r;
  cin>>l>>r;
  struct segtree ans=query(tree,0,n-1,1,l-1,r-1);
  cout<<ans.maxSum<<endl;	
 }
}
