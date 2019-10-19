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
void preorder(Tree*root)
{
 if(root==NULL)
  return;
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right);	
}
void inorder(Tree*root)
{
 if(root==NULL)
  return;
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right);	
}
void postorder(Tree*root)
{
 if(root==NULL)
  return;
 postorder(root->left);
 postorder(root->right);	
 cout<<root->data<<" ";
}
void levelorder(Tree*root)
{
 queue<Tree*> q;
 q.push(root);
 while(!q.empty())
 {
  Tree*tmp=q.front();
  cout<<tmp->data<<" ";
  q.pop();
  if(tmp->left!=NULL)
   q.push(tmp->left);
  if(tmp->right!=NULL)
   q.push(tmp->right); 	
 }	
}
int main(){
Tree*root=new Tree(1);
root->left=new Tree(2);
root->right=new Tree(3);
root->left->left=new Tree(4);
root->left->right=new Tree(5);
cout<<"Preorder Traversal: ";
preorder(root);
cout<<"\n";
cout<<"Inorder Traversal: ";
inorder(root);
cout<<"\n";
cout<<"Postorder Traversal: ";
postorder(root);
cout<<"\n";
cout<<"Level Order Traversal: ";
levelorder(root);
cout<<"\n";
return 0;
}
