#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	node*left,*right;
	node(int data)
	{
	 this->data=data;
	 left=right=NULL;	
	}
}Tree;
int height(Tree*root)
{
 if(root==NULL)
  return 0;
 return 1+max(height(root->left),height(root->right)); 	
}
int diameter(Tree*root)
{
 if(root==NULL)
  return 0;
 int lheight=height(root->left);
 int rheight=height(root->right);
 int ldiameter=diameter(root->left);
 int rdiameter=diameter(root->right);
 return max(lheight+rheight+1,max(ldiameter,rdiameter)); 	
}
int calheight(Tree*root,int &ans)
{
 if(root==NULL)
  return 0;
 int lheight=calheight(root->left,ans);
 int rheight=calheight(root->right,ans);
 ans=max(ans,1+lheight+rheight);
 return 1+max(lheight,rheight);	
}
int opt_diameter(Tree*root)
{
 if(root==NULL)
  return 0;
 int ans=INT_MIN;
 int height_of_tree=calheight(root,ans);
 return ans;	
}
int main(){
Tree*root=new Tree(1);
root->left=new Tree(2);
root->right=new Tree(3);
root->left->left=new Tree(4);
root->left->right=new Tree(5);
cout<<"Diameter of the Tree O(n^2): "<<diameter(root)<<endl;
cout<<"Diameter of the Tree O(n): "<<opt_diameter(root)<<endl;
return 0;
}
